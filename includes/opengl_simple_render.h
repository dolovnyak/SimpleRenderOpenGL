#ifndef SCOP_H
#define SCOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libft.h"
#include "matrix_vector_math.h"
#include "parse_json.h"

typedef struct	s_texture
{
	int				width;
	int				height;
	unsigned char	*image;
}				t_texture;

typedef struct	s_camera
{

}				t_camera;

typedef struct		s_raw_model
{
	unsigned int	vao;
	unsigned int	vbo;
	size_t			vertex_count;
}					t_raw_model;

typedef struct		s_render_model
{
	t_raw_model		raw_model;
}					t_render_model;

typedef struct	s_object
{
	t_render_model	render_model;
	GLuint			shader_program_id;
}				t_object;

typedef struct	s_scene
{
	t_object	*objects;
	t_camera	camera;
}				t_scene;

typedef struct	s_glsr_main
{
	t_scene		*scenes;
	GLFWwindow	*window;
}				t_glsr_main;

GLuint		create_shader_program(const char **files, const GLuint *shader_types);
t_texture	load_bmp(const char *filename);


#endif
