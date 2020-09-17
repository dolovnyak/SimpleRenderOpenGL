/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing_f.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 11:21:44 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/27 11:45:21 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**Absolutely the same function as for ints but we wanted the clear structure
*/

char		*flags_f_ps_or_signs(t_all *all, char *str, int *len)
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

char		*float_w_mz_processing(t_all *all, char *str, int *len, int flag)
{
	char	*new;
	int		i;

	i = 0;
	if ((all->flag_sign_minus == 1 || all->flag_plus == 1 ||
			all->flag_space == 1) && flag != 1)
	{
		str = flags_ps_or_signs(all, str, len);
		i = 1;
		all->width = all->width < *len ? *len : all->width;
	}
	new = ft_strnewsetchar(all->width, ' ');
	if (all->flag_minus == 1)
		ft_memcpy((void*)new, (const void*)str, *len);
	else if (all->flag_zero == 1 && flag != 1)
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
