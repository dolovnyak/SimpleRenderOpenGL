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

	return texture_id;
}

static int	get_render_model(t_render_model *render_model, t_raw_object *obj)
{
	t_vector		vertices;
	t_vector		uvs;
	t_vector		normals;
	float			*finish_vertices_data;

	render_model->texture_id = get_material(obj->material_path);
	if (load_obj_file(obj->model_path, &vertices, &uvs, &normals) < 0)
		return (ft_log_error("FAILURE LOAD OBJECT", -1));

	if (uvs.size == 0 && normals.size == 0)
	{
		t_vector finish_vector = ft_vector_create(sizeof(float));
		t_vec3	cur_vertex;
		t_vec2	cur_uv;
		for (int i = 0; i < vertices.size; i++)
		{
			vector_get_vec3_by_index(&cur_vertex, vertices, i);
//			vector_get_vec2_by_index(&cur_uv, uvs, i);
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
		t_vector finish_vector = ft_vector_create(sizeof(float));
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
