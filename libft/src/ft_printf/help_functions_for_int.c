/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions_for_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 00:00:19 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 11:46:14 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_str(va_list *ap, char *str, t_all *all, int base)
{
	if (base == 10)
	{
		if (all->modifier == 0)
			str = ft_ltoa_base(va_arg(*ap, int), 10);
		else if (all->modifier == 1)
			str = ft_ltoa_base((short int)va_arg(*ap, int), 10);
		else if (all->modifier == 2)
			str = ft_ltoa_base((char)va_arg(*ap, int), 10);
		else
			str = ft_ltoa_base(va_arg(*ap, long), 10);
	}
	else
	{
		base = base == 1 ? 10 : base;
		if (all->modifier == 0)
			str = ft_utoa_base(va_arg(*ap, unsigned int), base);
		else if (all->modifier == 1)
			str = ft_utoa_base((unsigned short)va_arg(*ap, unsigned int), base);
		else if (all->modifier == 2)
			str = ft_utoa_base((unsigned char)va_arg(*ap, unsigned int), base);
		else
			str = ft_utoa_base(va_arg(*ap, unsigned long), base);
	}
	return (str);
}

/*
**"Flag 1" is for the o-type or int8 and "flag 0" is for the others (diuxX)
*/

void	zero_p(t_all *all, char *str, int *len, int flag)
{
	if (all->precision == 0 && flag == 1 && all->flag_hash == 1)
		all->precision++;
	all->flag_hash = 0;
	all->flag_hash = flag == 0 ? 0 : all->flag_hash;
	if (all->precision == 0 && all->width == 0)
	{
		*len = 0;
		str[0] = '\0';
	}
	else if (all->precision == 0)
		str[0] = ' ';
}
