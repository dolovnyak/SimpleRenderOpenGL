/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:49:23 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 13:53:39 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		exception_handl_l(t_fcomp *fcomp, t_int128 bl, long exponent_l)
{
	fcomp->inf_check = 0;
	fcomp->nan_check = 0;
	bl = bl << 16;
	if (exponent_l == 32768)
	{
		if (bl == 0)
			return (fcomp->inf_check = 1);
		else
			return (fcomp->nan_check = 1);
	}
	if (exponent_l == 0 && bl == 0)
	{
		fcomp->len_integer = 2;
		fcomp->integer = (int*)ft_memalloc(sizeof(int));
		fcomp->fraction = (int*)ft_memalloc(sizeof(int));
		return (1);
	}
	return (0);
}

void	get_components_l(va_list *ap, t_fcomp *fcomp)
{
	long			exponent_l;
	t_int128		bl;
	long double		al;
	char			*b_fraction;
	char			*b_integer;

	al = va_arg(*ap, long double);
	bl = *((t_int128*)&al);
	fcomp->sign = ((fcomp->one << 79) & bl) ? -1 : 1;
	bl &= ~(fcomp->one << 79);
	exponent_l = bl >> 64;
	fcomp->len_fraction = 1;
	if (exception_handl_l(fcomp, bl, exponent_l))
		return ;
	exponent_l -= 16383;
	if (exponent_l < 64)
		b_fraction = bit_fraction_l(&exponent_l, bl, &fcomp->len_fraction);
	else
		b_fraction = ft_strdup("0");
	get_fraction(b_fraction, fcomp);
	b_integer = bit_integer_l(exponent_l, bl, &fcomp->len_integer);
	get_integer(b_integer, fcomp);
	norm_integer(fcomp);
	free(b_fraction);
	free(b_integer);
}

int		exception_handling(t_fcomp *fcomp, long b, long exponent)
{
	fcomp->inf_check = 0;
	fcomp->nan_check = 0;
	b = b << 12;
	if (exponent == 2047)
	{
		if (b == 0)
			return (fcomp->inf_check = 1);
		else
			return (fcomp->nan_check = 1);
	}
	if (exponent == 0 && b == 0)
	{
		fcomp->len_integer = 2;
		fcomp->integer = (int*)ft_memalloc(sizeof(int));
		fcomp->fraction = (int*)ft_memalloc(sizeof(int));
		return (1);
	}
	return (0);
}

void	get_components(va_list *ap, t_fcomp *fcomp)
{
	long			exponent;
	long			b;
	double			a;
	char			*b_fraction;
	char			*b_integer;

	a = va_arg(*ap, double);
	b = *((long*)&a);
	fcomp->sign = ((1lu << 63) & b) ? -1 : 1;
	b &= ~(1l << 63);
	exponent = b >> 52;
	fcomp->len_fraction = 1;
	if (exception_handling(fcomp, b, exponent))
		return ;
	exponent -= 1023;
	if (exponent < 52)
		b_fraction = bit_fraction(&exponent, b, &fcomp->len_fraction);
	else
		b_fraction = ft_strdup("0");
	get_fraction(b_fraction, fcomp);
	b_integer = bit_integer(exponent, b, &fcomp->len_integer);
	get_integer(b_integer, fcomp);
	norm_integer(fcomp);
	free(b_fraction);
	free(b_integer);
}
