/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:03:45 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 19:39:48 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*a;
	unsigned char		*b;
	size_t				i;

	i = 0;
	a = src;
	b = dst;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		b[i] = a[i];
		if (b[i] == (unsigned char)c)
			return (&dst[++i]);
		i++;
	}
	return (0);
}
