#include "opengl_simple_render.h"


int		load_obj_file(char *path, t_vector *vertices, t_vector *uvs, t_vector *normals)
{
	int			fd;
	char		*line;
	int			ret;
	t_vector	tmp_vertices;
	t_vector	tmp_uvs;
	t_vector	tmp_normals;
	t_vector	vertex_indices;
	t_vector	uv_indices;
	t_vector	normal_indices;

	tmp_vertices = ft_vector_create(sizeof(t_vec3));
	tmp_uvs = ft_vector_create(sizeof(t_vec2));
	tmp_normals = ft_vector_create(sizeof(t_vec3));

	vertex_indices = ft_vector_create(sizeof(unsigned));
	uv_indices = ft_vector_create(sizeof(unsigned));
	normal_indices = ft_vector_create(sizeof(unsigned));

	if ((fd = open(path, O_RDONLY)) == -1)
		return (ft_log_error("FAILED OPEN OBJ FILE", -1));

	while ((ret = ft_read_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) < 5)
			continue;
		if (line[0] == 'v' && line[1] == ' ')
		{
			t_vec3 vertex;
			if (sscanf(line + 2, "%f %f %f", &(vertex.x), &(vertex.y), &(vertex.z)) != 3)
				return (ft_log_error("FAILED PARSE VERTEX IN OBJ FILE", -1));
			ft_vector_push_back(&tmp_vertices, &vertex);
		}
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
		{
			t_vec2 uv;
			if (sscanf(line + 3, "%f %f", &(uv.x), &(uv.y)) != 2)
				return (ft_log_error("FAILED PARSE UV IN OBJ FILE", -1));
			ft_vector_push_back(&tmp_uvs, &uv);
		}
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
		{
			t_vec3 normal;
			if (sscanf(line + 3, "%f %f %f", &(normal.x), &(normal.y), &(normal.z)) != 3)
				return (ft_log_error("FAILED PARSE NORMAL IN OBJ FILE", -1));
			ft_vector_push_back(&tmp_normals, &normal);
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			unsigned int vertex_index[4], uv_index[4], normal_index[4];
			int matches = sscanf(line + 2, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
								 &vertex_index[0], &uv_index[0], &normal_index[0],
								 &vertex_index[1], &uv_index[1], &normal_index[1],
								 &vertex_index[2], &uv_index[2], &normal_index[2],
								 &vertex_index[3], &uv_index[3], &normal_index[3]);
			if (matches == 9)
			{
				ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[1]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[2]));
				ft_vector_push_back(&uv_indices, &(uv_index[0]));
				ft_vector_push_back(&uv_indices, &(uv_index[1]));
				ft_vector_push_back(&uv_indices, &(uv_index[2]));
				ft_vector_push_back(&normal_indices, &(normal_index[0]));
				ft_vector_push_back(&normal_indices, &(normal_index[1]));
				ft_vector_push_back(&normal_indices, &(normal_index[2]));
			}
			else if (matches == 12)
			{
				ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[1]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[2]));
				ft_vector_push_back(&uv_indices, &(uv_index[0]));
				ft_vector_push_back(&uv_indices, &(uv_index[1]));
				ft_vector_push_back(&uv_indices, &(uv_index[2]));
				ft_vector_push_back(&normal_indices, &(normal_index[0]));
				ft_vector_push_back(&normal_indices, &(normal_index[1]));
				ft_vector_push_back(&normal_indices, &(normal_index[2]));

				ft_vector_push_back(&vertex_indices, &(vertex_index[2]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[3]));
				ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
				ft_vector_push_back(&uv_indices, &(uv_index[2]));
				ft_vector_push_back(&uv_indices, &(uv_index[3]));
				ft_vector_push_back(&uv_indices, &(uv_index[0]));
				ft_vector_push_back(&normal_indices, &(normal_index[2]));
				ft_vector_push_back(&normal_indices, &(normal_index[3]));
				ft_vector_push_back(&normal_indices, &(normal_index[0]));
			}
			else
			{
				int matches = sscanf(line + 2, "%d %d %d %d",
						 &vertex_index[0], &vertex_index[1], &vertex_index[2], &vertex_index[3]);
				if (matches == 3)
				{
					ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[1]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[2]));
				}
				else if (matches == 4)
				{
					ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[1]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[2]));

					ft_vector_push_back(&vertex_indices, &(vertex_index[2]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[3]));
					ft_vector_push_back(&vertex_indices, &(vertex_index[0]));
				}
				else
					return (ft_log_error("FAILED PARSE OBJ FILE", -1));
			}
		}
		ft_strdel(&line);
	}
	if (ret < 0)
		return (ft_log_error("FAILED READ OBJ FILE", -1));
	ft_strdel(&line);
	close(fd);
	if (vertex_indices.size == 0 || tmp_vertices.size == 0)
		return (ft_log_error("FAILED PARSE OBJ FILE", -1));

	*vertices = ft_vector_create(sizeof(t_vec3));
	*uvs = ft_vector_create(sizeof(t_vec2))
	*normals = ft_vector_create(sizeof(t_vec3));
	for (int i = 0; i < vertex_indices.size; i++)
	{
		unsigned vertex_index;
		unsigned uv_index;
		unsigned normal_index;
		t_vec3 vertex;
		t_vec2 uv;
		t_vec3 normal;

		if (!(vector_get_unsigned_by_index(&vertex_index, vertex_indices, i)))
			return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));
		if (!(vector_get_vec3_by_index(&vertex, tmp_vertices, vertex_index - 1)))
			return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));
		ft_vector_push_back(vertices, &vertex);

		if (uv_indices.size > 0 && tmp_uvs.size > 0 && normal_indices.size > 0 && tmp_normals.size > 0)
		{
			if (!(vector_get_unsigned_by_index(&uv_index, uv_indices, i)))
				return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));
			if (!(vector_get_vec2_by_index(&uv, tmp_uvs, uv_index - 1)))
				return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));

			if (!(vector_get_unsigned_by_index(&normal_index, normal_indices, i)))
				return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));
			if (!(vector_get_vec3_by_index(&normal, tmp_normals, vertex_index - 1)))
				return (ft_log_error("C VECTOR SIZES DON'T CORRECT", -1));

			ft_vector_push_back(uvs, &uv);
			ft_vector_push_back(normals, &normal);
		}
	}
	ft_vector_free(&tmp_vertices);
	ft_vector_free(&tmp_uvs);
	ft_vector_free(&tmp_normals);
	ft_vector_free(&vertex_indices);
	ft_vector_free(&uv_indices);
	ft_vector_free(&normal_indices);
	return (1);
}