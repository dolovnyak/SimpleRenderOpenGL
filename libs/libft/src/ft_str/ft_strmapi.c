/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:36:42 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 23:29:15 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;

	i = -1;
	if (!s || !f || (!(a = ft_strnew(ft_strlen(s)))))
		return (0);
	while (s[++i])
		a[i] = f(i, s[i]);
	return (a);
}
