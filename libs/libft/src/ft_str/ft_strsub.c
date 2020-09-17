/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:12:30 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/22 03:34:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((a = (char*)ft_memalloc(len + 1)))
	{
		while (i < len)
		{
			a[i] = s[start];
			start++;
			i++;
		}
		a[i] = '\0';
	}
	return (a);
}
