/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_rounding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 04:10:34 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 13:42:33 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_len_integer(int len_s)
{
	int				res;

	res = 0;
	if (len_s < 10)
	{
		if (len_s % 3 == 0)
			res = len_s / 3;
		else
			res = len_s / 3 + 1;
	}
	else
	{
		if (len_s % 10 >= 0 && len_s % 10 <= 3)
			res = len_s / 10 + len_s / 5 + 1;
		else
			res = (len_s - (len_s / 10) * 10) / 7 + (len_s / 10) * 3 + 2;
	}
	return (res + 2);
}

void	norm_integer(t_fcomp *fcomp)
{
	register int	i;

	if (fcomp->len_integer == 2 && fcomp->integer[0] == 0)
		return ;
	i = fcomp->len_integer - 1;
	while (fcomp->integer[i] == 0)
		i--;
	fcomp->len_integer = i + 2;
}

void	processing_overflow_integerpart(t_fcomp *fcomp)
{
	register int	i;

	i = -1;
	while (++i < fcomp->len_integer && fcomp->integer[i] == 10)
	{
		fcomp->integer[i + 1]++;
		fcomp->integer[i] = 0;
	}
	if (i == fcomp->len_integer - 1)
		fcomp->len_integer++;
}

int		check_5(t_fcomp *fcomp, int count)
{
	register int	i;

	i = fcomp->len_fraction - count - 1;
	while (--i >= 0)
		if (fcomp->fraction[i] != 0)
			return (1);
	return (0);
}

char	*get_string_integer(t_fcomp *fcomp)
{
	char			*s;
	register int	i;
	register int	j;

	if (fcomp->fraction[fcomp->len_fraction - 1] == 5
			&& fcomp->integer[0] % 2 == 0)
		check_5(fcomp, 1) == 1 ? fcomp->integer[0]++ : fcomp->integer[0];
	else if (fcomp->fraction[fcomp->len_fraction - 1] >= 5)
		fcomp->integer[0]++;
	if (fcomp->integer[0] == 10)
		processing_overflow_integerpart(fcomp);
	s = ft_memalloc(fcomp->len_integer + 1);
	i = fcomp->len_integer - 1;
	j = -1;
	while (--i >= 0)
		s[++j] = fcomp->integer[i] + '0';
	return (s);
}
