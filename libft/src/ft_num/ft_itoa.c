/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:16:18 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/11 22:23:52 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define POZ(val) (val < 0 ? -val : val)

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;

	len = ft_numlen(n);
	s = (char*)ft_memalloc(len + 1);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	n = POZ(n);
	if (!s)
		return (0);
	s[--len] = n % 10 + '0';
	while (n /= 10)
		s[--len] = n % 10 + '0';
	if (&s[--len])
		s[len] = '-';
	return (s);
}
