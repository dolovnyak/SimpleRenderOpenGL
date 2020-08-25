/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:14:36 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/05 19:20:59 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		else
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
	}
	return (dst);
}
