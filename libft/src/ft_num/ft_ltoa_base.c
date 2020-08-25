/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:09:40 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/25 01:36:46 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(long value, int base)
{
	int		res;

	res = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		res++;
	}
	return (res);
}

char		*ft_ltoa_base(long nb, int base)
{
	int		i;
	char	*str;
	int		len;
	char	*main;

	if (!nb && !base && !(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	main = "0123456789ABCDEF";
	len = nb < 0 && base == 10 ? count_dig(nb, base) + 1 : count_dig(nb, base);
	str = ft_strnew(len);
	str[0] = nb < 0 ? '-' : '0';
	if (str[0] == '-')
		while (nb)
		{
			str[len - ++i] = main[-(nb % base)];
			nb /= base;
		}
	else
		while (nb)
		{
			str[len - ++i] = main[nb % base];
			nb /= base;
		}
	return (str);
}
