/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:11:03 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 19:58:38 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*a;
	unsigned char		*b;
	size_t				i;

	i = 0;
	a = src;
	b = dst;
	if (dst == src)
		return (dst);
	if (src > dst)
		while (i < len)
		{
			b[i] = a[i];
			i++;
		}
	else
		while (len > 0)
		{
			b[len - 1] = a[len - 1];
			len--;
		}
	return (dst);
}
