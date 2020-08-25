/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:08:25 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 23:21:26 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*a;
	unsigned int	i;

	i = -1;
	if (!s || !f || (!(a = ft_strnew(ft_strlen(s)))))
		return (0);
	while (s[++i])
		a[i] = f(s[i]);
	return (a);
}
