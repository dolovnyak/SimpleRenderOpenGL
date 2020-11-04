/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:23:26 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:23:27 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, int start, int len)
{
	char	*a;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((a = (char*)malloc(len + 1)))
	{
		while (i < len)
		{
			a[i] = s[start];
			start++;
			i++;
		}
		a[i] = '\0';
	}
	free(s);
	return (a);
}
