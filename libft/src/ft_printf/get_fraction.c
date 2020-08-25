/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:14:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 13:54:06 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*bit_fraction_l(long *exponent_l, t_int128 bl, int *len)
{
	register int	i;
	register int	j;
	t_int128		one;
	char			*b_fraction;

	one = 1;
	*len = (*exponent_l == -16383) ? 64 + 16382 : 64 - *exponent_l;
	b_fraction = ft_strnewsetchar(*len, '0');
	if (*exponent_l < 0)
	{
		if (!(bl << 16 != 0 && *exponent_l == -16383))
			b_fraction[*len - 65] = '1';
		i = 64;
		while (--i >= 0)
			b_fraction[*len - 1 - i] = ((one << i) & bl) ? '1' : '0';
	}
	else
	{
		j = -1;
		i = *len - 1;
		while (--i >= 0)
			b_fraction[++j] = ((one << i) & bl) ? '1' : '0';
	}
	*exponent_l = (*exponent_l == -16383) ? -16382 : *exponent_l;
	return (b_fraction);
}

char	*bit_fraction(long *exponent, long b, int *len)
{
	register int	i;
	register int	j;
	char			*b_fraction;

	*len = (*exponent == -1023) ? 53 + 1022 : 53 - *exponent;
	b_fraction = ft_memalloc(*len);
	if (*exponent < 0)
	{
		ft_memset((void*)b_fraction, '0', *len - 1);
		if (!(b << 12 != 0 && *exponent == -1023))
			b_fraction[*len - 54] = '1';
		i = 52;
		while (--i >= 0)
			b_fraction[*len - 2 - i] = ((1l << i) & b) ? '1' : '0';
	}
	else
	{
		j = -1;
		i = *len - 1;
		while (--i >= 0)
			b_fraction[++j] = ((1l << i) & b) ? '1' : '0';
	}
	*exponent = (*exponent == -1023) ? -1022 : *exponent;
	return (b_fraction);
}

void	countup_fraction(t_fcomp *fcomp, int *num, char bit, int *count)
{
	*count = -1;
	if (bit == '1')
		while (++*count < fcomp->len_fraction)
		{
			fcomp->fraction[*count] += num[*count];
			fcomp->fraction[*count + 1] += fcomp->fraction[*count] / 10;
			fcomp->fraction[*count] %= 10;
		}
	*count = -1;
}

void	get_negative_power(t_fcomp *fcomp, int *num, int i)
{
	int	count;

	count = fcomp->len_fraction - i - 3;
	while (++count < fcomp->len_fraction - 1)
		num[count] = num[count + 1];
	num[fcomp->len_fraction - 1] = 0;
	count = fcomp->len_fraction - i - 3;
	while (++count < fcomp->len_fraction)
		num[count] *= 5;
	count = fcomp->len_fraction - i - 3;
	while (++count < fcomp->len_fraction)
	{
		num[count + 1] += num[count] / 10;
		num[count] %= 10;
	}
}

void	get_fraction(char *b_fraction, t_fcomp *fcomp)
{
	register int	i;
	int				count;
	int				*num;

	fcomp->fraction = (int*)ft_memalloc((fcomp->len_fraction + 1) * 4);
	num = (int*)ft_memalloc((fcomp->len_fraction + 1) * 4);
	num[fcomp->len_fraction - 1] = 5;
	i = -1;
	while (b_fraction[++i])
	{
		countup_fraction(fcomp, num, b_fraction[i], &count);
		get_negative_power(fcomp, num, i);
	}
	free(num);
}
