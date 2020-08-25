/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:00:11 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/06 12:42:14 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchnum(const char *s, int c)
{
	size_t n;

	n = 0;
	if (s)
		while (*s)
		{
			if (*s == (unsigned char)c)
				n++;
			s++;
		}
	return (n);
}
