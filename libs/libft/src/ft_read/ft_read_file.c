/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:34:47 by sbecker           #+#    #+#             */
/*   Updated: 2020/11/05 01:54:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"
#include <stdio.h>

int		ft_read_file(const char *filename, char **out_data)
{
	int		fd;
	int		byte_count;
	char	buff[BUFF_SIZE];
	char	*file_data;
	int		len;

	len = 0;
	if (BUFF_SIZE <= 0 || !out_data ||
	(fd = open(filename, O_RDONLY)) < 0 || read(fd, buff, 0) <= -1)
		return (-1);
	file_data = ft_memalloc(sizeof(char));
	while ((byte_count = read(fd, buff, BUFF_SIZE)))
	{
		buff[byte_count] = '\0';
		file_data = ft_strjoinfree(file_data, buff);
		len += byte_count;
	}
	*out_data = file_data;
	close(fd);
	return (len);
}
