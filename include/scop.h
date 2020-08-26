#ifndef SCOP_H
#define SCOP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "libft.h"

typedef struct	s_texture
{
	int				width;
	int				height;
	unsigned char	*image;
}				t_texture;

GLuint		create_shader_program(const char **files, const GLuint *shader_types);
t_texture	load_bmp(const char *filename);

#endif
