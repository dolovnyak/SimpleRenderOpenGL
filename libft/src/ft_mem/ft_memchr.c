/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:04:29 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 19:40:36 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*a;
	size_t				i;

	i = 0;
	a = s;
	while (i < n)
	{
		if (a[i] == ((unsigned char)c))
			return ((unsigned char*)&s[i]);
		i++;
	}
	return (NULL);
}
