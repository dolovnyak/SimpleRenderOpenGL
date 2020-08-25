/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:10:00 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 23:46:07 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strwccpy(char *dst, char *src, int c)
{
	size_t	i;

	i = 0;
	while (src[i] != (unsigned char)c && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (&src[i]);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s == c)
		s++;
	arr = (char**)ft_memalloc((ft_strwcnumber(s, c) + 1) * sizeof(char*));
	if (!arr)
		return (0);
	while (*s)
	{
		if (!(arr[i] = (char*)ft_memalloc(ft_strwclen(s, c) + 1)))
			return (ft_dpclear(arr));
		s = ft_strwccpy(arr[i], (char*)s, c);
		while (*s == (unsigned char)c)
			s++;
		if (*s == '\0')
			return (arr);
		i++;
	}
	return (arr);
}
