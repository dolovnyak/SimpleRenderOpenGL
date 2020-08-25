/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:50:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 11:46:24 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_n(t_all *all, va_list *ap)
{
	int *ptr;

	ptr = va_arg(*ap, int*);
	*ptr = all->symbol_num;
}

char	*width_processing(char *str, int len, t_all *all)
{
	char *new;

	new = malloc(all->width);
	if (all->flag_minus == 1)
	{
		ft_memset((void*)new, ' ', all->width);
		ft_strncpy(new, str, len);
	}
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)new, '0', all->width);
		ft_strncpy(new + all->width - len, str, len);
	}
	else
	{
		ft_memset((void*)new, ' ', all->width);
		ft_strncpy(new + all->width - len, str, len);
	}
	ft_strdel(&str);
	return (new);
}

void	do_percent_or_uchar(t_all *all, va_list *ap, char *str, char f)
{
	int	len;

	len = 1;
	str = ft_strnew(len);
	if (f == 0)
		*str = '%';
	else
		*str = (unsigned char)va_arg(*ap, int);
	if (all->width > 1)
	{
		str = width_processing(str, 1, all);
		len = all->width;
	}
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;
	ft_strdel(&str);
}

char	*re_strncpy(char *src, int n)
{
	char	*new;
	int		i;

	new = ft_memalloc(n + 1);
	i = -1;
	while (++i < n)
		new[i] = src[i];
	ft_strdel(&src);
	return (new);
}

void	do_string(t_all *all, va_list *ap, char *str)
{
	int		len;

	if (!(str = ft_strdup(va_arg(*ap, char*))))
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	if (all->precision < len && all->precision != -1)
	{
		str = re_strncpy(str, all->precision);
		len = all->precision;
	}
	if (all->width > len)
	{
		str = width_processing(str, len, all);
		len = all->width;
	}
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, str, len);
	all->symbol_num += len;
	ft_strdel(&str);
}
