/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 07:54:52 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/23 08:33:27 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s, char const *s1)
{
	char	*check;
	char	*a;
	size_t	i;

	i = 0;
	if (!s || !s1)
		return (0);
	check = s;
	a = (char*)malloc(ft_strlen(s) + ft_strlen(s1) + 1);
	if (a)
	{
		while (*s)
		{
			a[i++] = *s;
			s++;
		}
		while (*s1)
		{
			a[i++] = *s1;
			s1++;
		}
		a[i] = '\0';
	}
	free(check);
	return (a);
}
