#ifndef SCOP_H
#define SCOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libft.h"
#include "matrix_vector_math.h"
#include "parse_json.h"

#define GLSR_PERSPECTIVE 1
#define GLSR_ORTHOGRAPHIC 2
#define MAX_KEYS 348
#define ANGLE_X_SPEED 0.5f
#define ANGLE_Y_SPEED 0.5f
#define ANGLE_Z_SPEED 0.5f

typedef struct		s_texture
{
	int				width;
	int				height;
	unsigned char	*image;
}					t_texture;

typedef struct		s_camera
{
	t_mat4			view;
}					t_camera;

typedef struct		s_render_model
{
	GLuint			vao;
	GLuint			vbo;
	size_t			vertex_count;
	GLuint			texture_id;
}					t_render_model;

typedef struct		s_object
{
	t_render_model	render_model;
	GLuint			shader_program_id;
	t_mat4			transform;
	t_mat4			world_model;
}					t_object;

typedef struct		s_scene
{
	t_object		*objects;
	int				objects_num;
	int 			cur_object_index;
	t_camera		camera;
	t_mat4			projection;
	int				projection_type;
}					t_scene;

typedef struct		s_glsr_main
{
	t_scene			*scenes;
	int				scenes_num;
	GLFWwindow		*window;
	int				frame_buffer_w;
	int				frame_buffer_h;
	int				previous_keys_map[MAX_KEYS];
	int				color_flag;
	int				flat_flag;
}					t_glsr_main;

GLuint				load_and_create_shader_program(const char **files, const GLuint *shader_types);
t_texture			load_bmp(const char *filename);
int					init(t_glsr_main *main, const char *config_path);
int					create_object_from_raw(t_object *obj, t_raw_object *raw_obj);
int					log_error(const char *p, int id);
int					load_obj_file(char *path, t_vector *vertices, t_vector *uvs, t_vector *normals);
void				events_processing(t_glsr_main *main, t_scene *scene, int w, int h);
void				objects_events_processing(t_glsr_main *main, t_scene *scene);


int		vector_get_vec3_by_index(t_vec3 *vec, t_vector vector, size_t index);
int		vector_get_vec2_by_index(t_vec2 *vec, t_vector vector, size_t index);
int		vector_get_unsigned_by_index(unsigned *value, t_vector vector, size_t index);

#endif
