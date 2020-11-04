/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_file_read_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:39:01 by sbecker           #+#    #+#             */
/*   Updated: 2020/11/05 01:55:49 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

static int		ft_new_line(char **str, char **line)
{
	size_t	i;
	char	*check;

	if (!(i = ft_strchrpos(*str, '\n')))
		return (0);
	if (i == 1)
	{
		*line = ft_strdup("\n");
		check = ft_strsub(*str, 1, ft_strlen(*str) - 1);
		ft_strdel(str);
		*str = check;
		return (1);
	}
	if ((*line = ft_strsub(*str, 0, i - 1)))
	{
		check = ft_strsub(*str, (unsigned int)i, ft_strlen(*str) - i);
		ft_strdel(str);
		*str = check;
		return (1);
	}
	return (-1);
}

static void		check_init_fd(t_rline *rline, int fd)
{
	if (rline->fd == fd)
		return ;
	if (rline->str)
		ft_strdel(&rline->str);
	rline->str = ft_strdup("");
	rline->fd = fd;
}

int				finish_read_file(t_rline *rline, char **line)
{
	if (rline->str)
		ft_strdel(&rline->str);
	ft_bzero(rline, sizeof(t_rline));
	*line = NULL;
	return (0);
}

int				ft_single_file_read_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_rline	rline;
	int				exit;
	size_t			read_size;

	if (BUFF_SIZE <= 0 || fd < 0 || !line || read(fd, buf, 0) <= -1)
		return (-1);
	check_init_fd(&rline, fd);
	while (1)
		if ((exit = ft_new_line(&rline.str, line)))
			return (exit == 1 ? 1 : -1);
		else if ((read_size = read(fd, buf, BUFF_SIZE)))
		{
			buf[read_size] = '\0';
			rline.str = ft_strjoinfree(rline.str, buf);
		}
		else if (rline.str && *rline.str)
		{
			*line = ft_strdup(rline.str);
			ft_strdel(&rline.str);
			return (1);
		}
		else
			return (finish_read_file(&rline, line));
}
