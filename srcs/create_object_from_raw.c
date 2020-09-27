#include "opengl_simple_render.h"

static GLuint	get_material(char *material_path)
{
	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	t_texture raw_texture = load_bmp(material_path);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, raw_texture.width, raw_texture.height, 0,
				 GL_RGB, GL_UNSIGNED_BYTE, raw_texture.image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	free(raw_texture.image);

	return texture_id;
}

static void	center_vertices(t_vector *vec_vertices)
{
	t_vec3		min;
	t_vec3		max;
	t_vec3		center;
	t_vec3		*vertices;

	vertices = (t_vec3 *)vec_vertices->elems_data;
	min = vertices[0];
	max = vertices[0];
	for (int i = 1; i < vec_vertices->size; i++)
	{
		min.x = min.x > vertices[i].x ? vertices[i].x : min.x;
		min.y = min.y > vertices[i].y ? vertices[i].y : min.y;
		min.z = min.z > vertices[i].z ? vertices[i].z : min.z;
		max.x = max.x < vertices[i].x ? vertices[i].x : max.x;
		max.y = max.y < vertices[i].y ? vertices[i].y : max.y;
		max.z = max.z < vertices[i].z ? vertices[i].z : max.z;
	}
	center = mvm_multiply_v3_f(mvm_add_v3_v3(min, max), 0.5f);
	for (int i = 0; i < vec_vertices->size; i++)
	{
		vertices[i].x -= center.x;
		vertices[i].y -= center.y;
		vertices[i].z -= center.z;
	}
}

static int	get_render_model(t_render_model *render_model, t_raw_object *obj)
{
	t_vector		vertices;
	t_vector		uvs;
	t_vector		normals;
	float			*finish_vertices_data;
	t_vector finish_vector = ft_vector_create(sizeof(float));

	render_model->texture_id = get_material(obj->material_path);
	if (load_obj_file(obj->model_path, &vertices, &uvs, &normals) < 0)
		return (ft_log_error("FAILURE LOAD OBJECT", -1));

	center_vertices(&vertices);
	if (uvs.size == 0 && normals.size == 0)
	{
		t_vec3	cur_vertex;
		t_vec2	cur_uv;
		for (int i = 0; i < vertices.size; i++)
		{
			vector_get_vec3_by_index(&cur_vertex, vertices, i);
			cur_uv.x = (0.5f + atan2f(cur_vertex.z, cur_vertex.x) / (float)M_PI * 0.5f) * 15.f;
			cur_uv.y = (cur_vertex.y / 10.0f) * 20.f;
			ft_vector_push_back(&finish_vector, &cur_vertex.x);
			ft_vector_push_back(&finish_vector, &cur_vertex.y);
			ft_vector_push_back(&finish_vector, &cur_vertex.z);
			ft_vector_push_back(&finish_vector, &cur_uv.x);
			ft_vector_push_back(&finish_vector, &cur_uv.y);
		}
		finish_vertices_data = (float *)finish_vector.elems_data;
		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, finish_vector.size * sizeof(float), finish_vertices_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
		render_model->vao = VAO;
		render_model->vbo = VBO;
		render_model->vertex_count = vertices.size;
	}
	else
	{
		t_vec3	cur_vertex;
		t_vec2	cur_uv;
		for (int i = 0; i < vertices.size; i++)
		{
			vector_get_vec3_by_index(&cur_vertex, vertices, i);
			vector_get_vec2_by_index(&cur_uv, uvs, i);
			ft_vector_push_back(&finish_vector, &cur_vertex.x);
			ft_vector_push_back(&finish_vector, &cur_vertex.y);
			ft_vector_push_back(&finish_vector, &cur_vertex.z);
			ft_vector_push_back(&finish_vector, &cur_uv.x);
			ft_vector_push_back(&finish_vector, &cur_uv.y);
		}
		finish_vertices_data = (float *)finish_vector.elems_data;
		GLuint VAO;
		glGenVertexArrays(1, &VAO);
		GLuint VBO;
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, finish_vector.size * sizeof(float), finish_vertices_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
		render_model->vao = VAO;
		render_model->vbo = VBO;
		render_model->vertex_count = vertices.size;
	}
	ft_vector_free(&finish_vector);
	ft_vector_free(&vertices);
	ft_vector_free(&uvs);
	ft_vector_free(&normals);
	return (1);
}

int		create_object_from_raw(t_object *obj, t_raw_object *raw_obj)
{
	obj->shader_program_id = load_and_create_shader_program(
			(const char *[]) {raw_obj->vertex_path, raw_obj->fragment_path, NULL},
			(const GLuint[]) {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, 0});
	obj->transform = mvm_identity_m4x4();
	obj->world_model = mvm_identity_m4x4();
	obj->world_model = mvm_translate(obj->world_model, raw_obj->pos);
	if (get_render_model(&(obj->render_model), raw_obj) < 0)
		return (ft_log_error("FAILURE GETTING RENDER MODEL", -1));
	return (1);
}
