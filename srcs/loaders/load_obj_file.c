#include "opengl_simple_render.h"

int		ft_isblank(char c)
{
	return ((c == ' ' || c == '\n' || c == '\v' ||
			 c == '\t' || c == '\r' || c == '\f'));
}

double	ft_atof(const char *str)
{
	int		sign;
	double	i;
	double	value;
	int		exponent;

	i = 1;
	sign = 0;
	value = 0;
	while (ft_isblank(*str))
		str++;
	*str == '-' ? sign = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while ('0' <= *str && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str == '.' && (str++))
		while ('0' <= *str && *str <= '9')
			value += (*str++ - '0') / (i *= 10);
	if (*str == 'E' && (str++))
	{
		exponent = ft_atoi(str);
		if (exponent != 0)
			value = value * pow(10, exponent);
	}
	return (sign == 1 && value > 0 ? -value : value);
}

void	get_numbers(char *path, int *vertices_num, int *normals_num, int *uvs_num)
{
	int		fd;
	char	*line;

	*vertices_num = 0;
	*normals_num = 0;
	*uvs_num = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		ft_exit_with_error(
				(const char *[]){"obj file", path,"doesn't correct", NULL}, -1);
	while (ft_read_line(fd, &line) > 0)
	{
		if (line[0] == 'v' && line[1] == ' ')
			(*vertices_num)++;
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
			(*normals_num)++;
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
			(*uvs_num)++;
		ft_strdel(&line);
	}
	close(fd);
}

GLfloat	*append_vertices(GLfloat *array, char *line, int *length)
{
	int		i;
	int		j;
	char	**tab;
	GLfloat	*new;

	tab = ft_strsplit(&line[1], ' ');
	*length += 6;
	new = (GLfloat*)malloc(sizeof(GLfloat) * *length);
	i = -1;
	while (++i < *length - 6)
		new[i] = array[i];
	free(array);
	array = new;
	j = -1;
	while (tab[++j] != NULL)
	{
		array[*length - 6 + j] = (GLfloat)ft_atof(tab[j]);
		array[*length - 3 + j] = j * 0.66f;
		ft_strdel(&tab[j]);
	}
	ft_strdel(&tab[j]);
	free(tab);
	tab = NULL;
	return (array);
}



//void	get_obj_file_data(char *path, GLfloat *vertices, GLfloat *normals, GLfloat *uvs)
//{
//	int		fd;
//	char	*line;
//
//	while (ft_read_line(fd, &line) > 0)
//	{
//		if (line[0] == 'v' && line[1] == ' ')
//			vertices = append_vertices(e->model.vertices, line, &v);
//		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
//			normals = append_normals();
//		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
//			uvs = append_uvs();
//		ft_strdel(&line);
//	}
//}

//void	load_obj_file(char *path, GLfloat *final_vertices)
//{
//	int		fd;
//	int		v;
//	int		f;
//	char	*line;
//
//	while (ft_read_line(fd, &line) > 0)
//	{
//		if (line[0] == 'v' && line[1] == ' ')
//			final_vertices = append_vertices(final_vertices, line, &v);
//		else if (line[0] == 'f' && line[1] == ' ')
//			e->model.indices = append_indices(e->model.indices, line, &f);
//		ft_strdel(&line);
//	}


//	int		vertices_num;
//	int		normals_num;
//	int		uvs_num;
//	GLfloat *vertices;
//	GLfloat *normals;
//	GLfloat *uvs;
//
//	get_numbers(&vertices_num, &normals_num, &uvs_num);
//	vertices = (GLfloat *)ft_memalloc(sizeof(GLfloat) * vertices_num);
//	normals = (GLfloat *)ft_memalloc(sizeof(GLfloat) * normals_num);
//	uvs = (GLfloat *)ft_memalloc(sizeof(GLfloat) * uvs_num);
//}