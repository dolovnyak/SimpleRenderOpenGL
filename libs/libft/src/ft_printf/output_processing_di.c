/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/27 11:45:11 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flags_ps_or_signs(t_all *all, char *str, int *len)
{
	char	*new;

	if (all->flag_sign_minus == 1)
	{
		new = ft_strnew((size_t)*len + 1);
		new[0] = '-';
	}
	else if (all->flag_plus == 1)
	{
		new = ft_strnew((size_t)*len + 1);
		new[0] = '+';
	}
	else if (all->flag_space == 1)
	{
		new = ft_strnew((size_t)*len + 1);
		new[0] = ' ';
	}
	else
		return (str);
	++(*len);
	ft_strcpy(&new[1], str);
	ft_strdel(&str);
	return (new);
}

char		*int_precision_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->precision);
	ft_memset((void*)new, '0', (all->precision - *len));
	ft_strcpy(&new[all->precision - *len], str);
	if (all->flag_sign_minus == 1 || all->flag_plus == 1
			|| all->flag_space == 1)
		new = flags_ps_or_signs(all, new, &all->precision);
	*len = all->precision;
	ft_strdel(&str);
	return (new);
}

char		*int_w_mz_processing(t_all *all, char *str, int *len)
{
	char	*new;
	int		i;

	i = 0;
	if (all->precision < *len && (all->flag_sign_minus == 1 ||
				all->flag_plus == 1 || all->flag_space == 1))
	{
		str = flags_ps_or_signs(all, str, len);
		i = 1;
		all->width = all->width < *len ? *len : all->width;
	}
	new = ft_strnewsetchar(all->width, ' ');
	if (all->flag_minus == 1)
		ft_memcpy((void*)new, (const void*)str, *len);
	else if (all->flag_zero == 1 && all->precision < 0)
	{
		new[0] = str[0];
		ft_memset((void*)&new[i], '0', (all->width - *len));
		ft_strcpy(&new[all->width - *len + i], &str[i]);
	}
	else
		ft_strcpy(&new[all->width - *len], str);
	*len = all->width;
	ft_strdel(&str);
	return (new);
}
