/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:08:28 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 23:09:18 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*a;
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	a = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (a)
	{
		while (*s1)
		{
			a[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			a[i] = *s2;
			i++;
			s2++;
		}
		a[i] = '\0';
	}
	return (a);
}
