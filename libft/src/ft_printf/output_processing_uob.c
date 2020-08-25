/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/27 11:45:30 by sschmele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*intu82_p_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->precision);
	ft_memset((void*)new, '0', (all->precision - *len));
	ft_strcpy(&new[all->precision - *len], str);
	*len = all->precision;
	ft_strdel(&str);
	return (new);
}

char		*intu82_w_mz_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->width);
	if (all->flag_minus == 1)
	{
		ft_memcpy((void*)new, (const void*)str, *len);
		ft_memset((void*)&new[*len], ' ', (all->width - *len));
	}
	else if (all->flag_zero == 1 && all->precision < 0)
	{
		ft_memset((void*)new, '0', (all->width - *len));
		ft_strcpy(&new[all->width - *len], str);
	}
	else
	{
		ft_memset((void*)new, ' ', (all->width - *len));
		ft_strcpy(&new[all->width - *len], str);
	}
	*len = ft_strlen(new);
	ft_strdel(&str);
	return (new);
}

/*
**Hash flag works only if there are no other flags, if there us only width
**more than length and if precision is less or equals length. There comes
**only zero before the nb
*/

char		*int8_h_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew((size_t)(*len + 1));
	new[0] = '0';
	ft_strcpy(&new[1], str);
	*len += 1;
	all->flag_hash = 0;
	ft_strdel(&str);
	return (new);
}
