/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <sbecker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:48:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/03/27 10:46:59 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initialization(t_all *all)
{
	all->flag_sign_minus = 0;
	all->flag_minus = 0;
	all->flag_plus = 0;
	all->flag_space = 0;
	all->flag_zero = 0;
	all->flag_hash = 0;
	all->width = 0;
	all->precision = -1;
	all->modifier = 0;
	all->type = 0;
}

char		*processing_and_output(t_all *all, char *s, va_list *ap)
{
	s = check_flags(all, ++s);
	s = check_width_or_precision(all, s, ap, 0);
	if (*s == '.')
	{
		all->precision = 0;
		s = check_width_or_precision(all, ++s, ap, 1);
	}
	s = check_modifier(all, s);
	s = check_type_and_output(all, ap, s);
	return (s);
}

char		*output_nonpercent_symbs(t_all *all, char *s)
{
	register int i;

	i = 0;
	while (s[i] != '%' && s[i])
		i++;
	all->fin_str = merge_strings(all->fin_str, all->symbol_num, s, i);
	all->symbol_num += i;
	return (s + i);
}

char		*merge_strings(char *s1, int len_1, char *s2, size_t n)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = ft_strnew(len_1 + n)))
		return (NULL);
	ft_memcpy(new, s1, len_1);
	while (i < len_1)
		i++;
	while ((size_t)j < n)
		new[i++] = s2[j++];
	ft_strdel(&s1);
	return (new);
}

int			ft_printf(const char *str, ...)
{
	t_all	all;
	va_list	ap;
	char	*tmp_s;
	char	*s;

	s = ft_strdup(str);
	tmp_s = s;
	va_start(ap, str);
	all.symbol_num = 0;
	all.fin_str = ft_memalloc(1);
	while (*s)
	{
		if (*s == '%')
		{
			initialization(&all);
			s = processing_and_output(&all, s, &ap);
		}
		else
			s = output_nonpercent_symbs(&all, s);
	}
	write(1, all.fin_str, all.symbol_num);
	va_end(ap);
	free(tmp_s);
	free(all.fin_str);
	return (all.symbol_num);
}
