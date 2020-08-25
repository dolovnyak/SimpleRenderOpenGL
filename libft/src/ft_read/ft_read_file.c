#include "ft_read.h"
#include <stdio.h>

int		ft_read_file(const char *filename, char **out_data)
{
	int		fd;
	int		tmp;
	char	buff[BUFF_SIZE];
	char	*file_data;

	if (BUFF_SIZE <= 0 || !out_data ||
	(fd = open(filename, O_RDONLY)) < 0 || read(fd, buff, 0) <= -1)
		return (-1);
	file_data = ft_strnew(BUFF_SIZE);
	while ((tmp = read(fd, buff, BUFF_SIZE)))
	{
		buff[tmp] = '\0';
		file_data = ft_strjoinfree(file_data, buff);
	}
	close(fd);
	*out_data = file_data;
	return 1;
}

//int ft_read_file(const char *filename, char **out_data)
//{
//	size_t	file_size;
//	FILE	*fd;
//	char	*buf;
//
//	fd = fopen(filename, "r");
//	if (!fd)
//	{
//		printf("ERROR: Open kernel file '%s'\n", filename);
//		exit(-1);
//	}
//	fseek(fd, 0, SEEK_END);
//	file_size = ftell(fd);
//	rewind(fd);
//	buf = (char*)malloc(file_size + 1);
//	fread(buf, sizeof(char), file_size, fd);
//	buf[file_size] = '\0';
//	fclose(fd);
//	*out_data = buf;
//}