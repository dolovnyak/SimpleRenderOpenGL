/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:41:49 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 19:50:53 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;
	size_t			i;

	if (n == 0 || s1 == s2)
		return (0);
	a1 = (unsigned char*)s1;
	a2 = (unsigned char*)s2;
	i = 0;
	while (i + 1 < n && a1[i] == a2[i])
		i++;
	return (a1[i] - a2[i]);
}
