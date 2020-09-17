/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcharmalloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:14:32 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/13 19:20:30 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewsetchar(size_t size, char c)
{
	char	*s;

	if (!(s = malloc(size + 1)))
		return (0);
	ft_memset(s, c, size);
	s[size] = 0;
	return (s);
}
