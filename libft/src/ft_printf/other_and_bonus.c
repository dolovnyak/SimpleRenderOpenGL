/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_and_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:19:15 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/27 12:15:25 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**P-type with zero works differently as int16x type with hash.
**Therefore we decided to make other function. P-type works only with width and
**minus flag.
*/

void		do_ptype(t_all *all, va_list *ap, char *str)
{
	int		len;
	char	*new;

	str = ft_utoa_base(va_arg(*ap, unsigned long), 16);
	len = ft_strlen(str);
	if (all->precision == 0)
		zero_p(all, str, &len, 0);
	str = int16x_h_processing(all, str, &len);
	do_lower(str);
	if (all->width >= len)
	{
		new = ft_strnewsetchar(all->width, ' ');
		if (all->flag_minus == 1)
			ft_memcpy((void*)new, (const void*)str, len);
		else
			ft_strcpy(&new[all->width - len], str);
		len = all->width;
		all->fin_str = merge_strings(all->fin_str, all->symbol_num, new, len);
		free(new);
	}
	else
		all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;
	free(str);
}

/*
**Width and flags zero and minus can work with other than type-letters letters.
**For example: b, k, m, r, w, y.
*/

void		do_letter_wzm(t_all *all, char *str, char s)
{
	all->width = all->width == 0 ? 1 : all->width;
	if ((s >= 0 && s <= 32) || s == 127)
	{
		str = ft_strnew(0);
		all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, 1);
		all->symbol_num += 1;
		free(str);
	}
	else
	{
		str = ft_strnewsetchar(all->width, ' ');
		if (all->flag_minus == 1)
			str[0] = s;
		else if (all->flag_zero == 1)
		{
			ft_memset((void*)str, '0', (all->width - 1));
			str[all->width - 1] = s;
		}
		else
			str[all->width - 1] = s;
		all->fin_str = merge_strings(all->fin_str, all->symbol_num,
				str, all->width);
		all->symbol_num += all->width;
		free(str);
	}
}

/*
**We could use the int_w_mz_processing function but there is a condition about
**precision and precision with floats works differently from ints so the
**function is almost copied but without that condition.
*/

void		do_int2(t_all *all, va_list *ap, char *str)
{
	int		len;

	if (all->modifier == 0)
		str = ft_utoa_base(va_arg(*ap, unsigned int), 2);
	else if (all->modifier == 1)
		str = ft_utoa_base((unsigned short)va_arg(*ap, unsigned int), 2);
	else if (all->modifier == 2)
		str = ft_utoa_base((unsigned char)va_arg(*ap, unsigned int), 2);
	else
		str = ft_utoa_base(va_arg(*ap, unsigned long), 2);
	len = ft_strlen(str);
	if (str[0] == '0')
		zero_p(all, str, &len, 0);
	if (all->precision >= len)
		str = intu82_p_processing(all, str, &len);
	if (all->width >= len)
		str = intu82_w_mz_processing(all, str, &len);
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;
	free(str);
}
