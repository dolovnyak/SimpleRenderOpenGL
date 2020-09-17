/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:05:30 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 13:44:59 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(t_all *all, char *s)
{
	while (*s == '-' || *s == '0' || *s == '+' || *s == '#' || *s == ' ')
	{
		if (*s == '-')
			all->flag_minus = 1;
		else if (*s == '+')
			all->flag_plus = 1;
		else if (*s == '0')
			all->flag_zero = 1;
		else if (*s == ' ')
			all->flag_space = 1;
		else if (*s == '#')
			all->flag_hash = 1;
		s++;
	}
	if (all->flag_space == 1 && all->flag_plus == 1)
		all->flag_space = 0;
	if (all->flag_zero == 1 && all->flag_minus == 1)
		all->flag_zero = 0;
	return (s);
}

char	*check_width_or_precision(t_all *all, char *s, va_list *ap, char flag)
{
	if (*s == '*')
	{
		if (flag == 0)
			all->width = va_arg(*ap, int);
		else
			all->precision = va_arg(*ap, int);
		s++;
	}
	else if (*s >= '0' && *s <= '9')
	{
		if (flag == 0)
			all->width = ft_atoi(s);
		else
			all->precision = ft_atoi(s);
		while (*s >= '0' && *s <= '9')
			s++;
	}
	return (s);
}

char	*check_modifier(t_all *all, char *s)
{
	if (*s == 'h')
	{
		if (*(s + 1) == 'h')
			all->modifier = 2;
		else
			all->modifier = 1;
	}
	else if (*s == 'l' || *s == 'j' || *s == 'z')
	{
		if (*(s + 1) == 'l')
			all->modifier = 4;
		else
			all->modifier = 3;
	}
	else if (*s == 'L')
		all->modifier = 5;
	while (*s == 'h' || *s == 'l' || *s == 'L' || *s == 'j' || *s == 'z')
		s++;
	return (s);
}

char	*check_more_type(t_all *all, va_list *ap, char *s)
{
	char	*str;

	str = NULL;
	if (*s == 'f')
		do_float(all, ap, str);
	else if (*s == 'b')
		do_int2(all, ap, str);
	else if (*s == 's')
		do_string(all, ap, str);
	else if (*s == 'c' || *s == 'C')
		do_percent_or_uchar(all, ap, str, 1);
	else if (*s == 'p')
		do_ptype(all, ap, str);
	else if (*s == 'n')
		do_n(all, ap);
	else if (*s == '%')
		do_percent_or_uchar(all, ap, str, 0);
	else
		do_letter_wzm(all, str, *s);
	return (s);
}

char	*check_type_and_output(t_all *all, va_list *ap, char *s)
{
	char	*str;

	str = NULL;
	if (*s == 'O' || *s == 'D' || *s == 'U')
		all->modifier = 3;
	if (*s == 'd' || *s == 'i' || *s == 'D')
		do_int(all, ap, str);
	else if (*s == 'u' || *s == 'U')
		do_uint(all, ap, str);
	else if (*s == 'o' || *s == 'O')
		do_int8(all, ap, str);
	else if (*s == 'x')
		do_int16x(all, ap, str);
	else if (*s == 'X')
		do_int16xupper(all, ap, str);
	else if (*s == 'F')
	{
		all->type = 'F';
		do_float(all, ap, str);
	}
	else
		s = check_more_type(all, ap, s);
	s++;
	return (s);
}
