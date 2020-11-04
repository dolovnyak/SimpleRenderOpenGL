/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:14:17 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:14:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 50

typedef struct	s_read_line
{
	char		*str;
	int			fd;
}				t_rline;

#endif
