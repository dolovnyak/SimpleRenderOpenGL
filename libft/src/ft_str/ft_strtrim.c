/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:51:25 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/12 17:25:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*a;
	unsigned int	i;
	unsigned int	begin;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return (ft_strdup(""));
	begin = i;
	while (s[i])
		i++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	a = (char*)ft_memalloc(i - begin + 2);
	if (a)
		ft_strncpy(a, &(s[begin]), i - begin + 1);
	return (a);
}
