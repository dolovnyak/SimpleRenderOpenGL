#include "scop.h"

int		is_input_correct(const char **files, const GLuint *shader_types)
{
	int	file_len;
	int	shader_len;

	file_len = 0;
	shader_len = 0;
	while (files[file_len])
		file_len++;
	while (shader_types[shader_len])
		shader_len++;
	if (file_len == 0 || file_len != shader_len)
		return 0;
	return 1;
}

GLuint	create_shader(const char *filename, GLuint shader_type)
{
	GLint	success;
	GLuint	shader;
	char	*shader_source;
	char	info_log[512];

	if (ft_read_file(filename, &shader_source) == -1)
		ft_exit_with_error((const char* [])
		{"FILENAME: ", filename, " DOESN'T CORRECT.", NULL}, -1);
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, (const GLchar **)&shader_source, NULL);
	glCompileShader(shader);
	free(shader_source);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		ft_exit_with_error((const char *[])
		{"SHADER: ", filename, " COMPILATION ERROR\n", info_log, NULL}, -1);
	}
	return (shader);
}

GLuint	create_shader_program(const char **files, const GLuint *shader_types)
{
	GLchar	info_log[512];
	GLuint	shader_program;
	int		success;
	int		i;

	if (!is_input_correct(files, shader_types))
		ft_exit_with_error((const char *[])
		{"SHADERS INPUT DOESN'T CORRECT.", NULL}, -1);
	shader_program = glCreateProgram();
	i = -1;
	while (files[++i])
	{
		GLuint shader = create_shader(files[i], shader_types[i]);
		glAttachShader(shader_program, shader);
		glDeleteShader(shader);
	}
	glLinkProgram(shader_program);
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program, 512, NULL, info_log);
		ft_exit_with_error((const char *[])
		{"SHADER PROGRAM COMPILATION FAILED.", info_log, NULL}, -1);
	}
	return shader_program;
}
