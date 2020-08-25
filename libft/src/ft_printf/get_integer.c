/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 01:07:03 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 13:55:17 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*bit_integer_l(long exponent_l, t_int128 bl, int *len)
{
	register int	i;
	t_int128		one;
	char			*b_integer;

	one = 1;
	if (exponent_l < 0)
	{
		*len = 2;
		return (ft_strdup("0"));
	}
	*len = exponent_l + 1;
	b_integer = ft_memalloc(*len + 2);
	ft_memset((void*)b_integer, '0', *len + 1);
	b_integer[0] = '1';
	i = 0;
	if (*len <= 63)
		while (++i < *len)
			b_integer[i] = ((one << (63 - i)) & bl) ? '1' : '0';
	else
		while (++i < 63)
			b_integer[i] = ((one << (63 - i)) & bl) ? '1' : '0';
	return (b_integer);
}

char	*bit_integer(long exponent, long b, int *len)
{
	register int	i;
	char			*b_integer;

	if (exponent < 0)
	{
		*len = 2;
		return (ft_strdup("0"));
	}
	*len = exponent + 1;
	b_integer = ft_memalloc(*len + 2);
	ft_memset((void*)b_integer, '0', *len + 1);
	b_integer[0] = '1';
	i = 0;
	if (*len <= 52)
		while (++i < *len)
			b_integer[i] = ((1l << (52 - i)) & b) ? '1' : '0';
	else
		while (++i <= 52)
			b_integer[i] = ((1l << (52 - i)) & b) ? '1' : '0';
	return (b_integer);
}

void	get_power(int power, int *num, t_fcomp *fcomp)
{
	int				count;
	int				p_count;

	ft_memset((void*)num, 0, (fcomp->len_integer) * sizeof(int));
	num[0] = 1;
	p_count = 0;
	while (++p_count <= power)
	{
		count = -1;
		while (++count < fcomp->len_integer)
			num[count] *= 2;
		count = -1;
		while (++count < fcomp->len_integer)
		{
			num[count + 1] += num[count] / 10;
			num[count] %= 10;
		}
	}
}

void	countup_integer(t_fcomp *fcomp, int *num)
{
	register int	count;

	count = -1;
	while (++count < fcomp->len_integer)
	{
		fcomp->integer[count] += num[count];
		fcomp->integer[count + 1] += fcomp->integer[count] / 10;
		fcomp->integer[count] %= 10;
	}
}

void	get_integer(char *b_integer, t_fcomp *fcomp)
{
	register int	i;
	int				power;
	int				*num;

	power = fcomp->len_integer - 1;
	if (fcomp->len_integer != 2)
		fcomp->len_integer = find_len_integer(fcomp->len_integer);
	fcomp->integer = (int*)ft_memalloc((fcomp->len_integer + 1) * sizeof(int));
	num = (int*)malloc((fcomp->len_integer + 1) * sizeof(int));
	i = -1;
	while (b_integer[++i])
	{
		if (b_integer[i] == '1')
		{
			get_power(power, num, fcomp);
			countup_integer(fcomp, num);
		}
		power--;
	}
	free(num);
}
