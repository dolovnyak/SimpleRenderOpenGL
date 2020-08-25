/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschmele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:05:26 by sschmele          #+#    #+#             */
/*   Updated: 2019/03/27 10:53:21 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**If only precision is more than the nb's length. If not - will not change.
**During this step the nb gets as many zeros before it as precision minus
**length of the nb. Examples: precision = 7, nb = 34 (length is 2),
**the result will be: 0000034. If there is flag hash (#) -
**it should be processed before width and after precision.
*/

char		*int16_p_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->precision);
	ft_memset((void*)new, '0', (all->precision - *len));
	ft_strcpy(&new[all->precision - *len], str);
	*len = all->precision;
	ft_strdel(&str);
	if (all->flag_hash == 1)
		new = int16x_h_processing(all, new, len);
	return (new);
}

/*
**Comes to the function if only the width is more than the nb's length and
**the precision is less than zero. Flag hash can work with all the flags but
**with zero flag it works differently. Also after the processing of hash flag
**the nb's length changes, so it is checked. Examples: nb = S32A
**(in order to check width and minus flag, the nb's length = 2), width = 8,
**with hash = S    0х32A, with minus = S0х32    A,
**with zero and without precision (with precision is ignored) = S00000032A,
**without flags =  S      32A. With hash and minus = S0х32    A,
**with hash and zero (without precision) = S0х000032А.
*/

char		*int16_w_hmz_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnewsetchar(all->width, ' ');
	if ((all->flag_hash == 1 && all->flag_zero == 0) || (all->flag_hash == 1
				&& all->flag_zero == 1 && all->width == *len + 1))
	{
		str = int16x_h_processing(all, str, len);
		all->width = all->width < *len ? *len : all->width;
	}
	if (all->flag_minus == 1)
		ft_memcpy((void*)new, (const void*)str, *len);
	else if (all->flag_zero == 1)
	{
		ft_memset((void*)new, '0', (all->width - *len));
		ft_strcpy(&new[all->width - *len], str);
		if (all->flag_hash == 1)
			new[1] = 'X';
	}
	else
		ft_strcpy(&new[all->width - *len], str);
	*len = all->width;
	ft_strdel(&str);
	return (new);
}

/*
**If nb comes already after precision, flag zero will be ignored,
**and flag hash already processed. Plus the nb can come if precision is
**more than 0 but less than length.
*/

char		*int16_w_hm_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew(all->width);
	if (all->flag_hash == 1)
	{
		str = int16x_h_processing(all, str, len);
		all->width = all->width < *len ? *len : all->width;
	}
	if (all->flag_minus == 1)
	{
		ft_memset((void*)&new[*len], ' ', (all->width - *len));
		ft_memcpy((void*)new, (const void*)str, *len);
	}
	else
	{
		ft_memset((void*)new, ' ', (all->width - *len));
		ft_strcpy(&new[all->width - *len], str);
	}
	*len = all->width;
	ft_strdel(&str);
	return (new);
}

/*
**Processing of the hash flag
*/

char		*int16x_h_processing(t_all *all, char *str, int *len)
{
	char	*new;

	new = ft_strnew((size_t)(*len + 2));
	new[0] = '0';
	new[1] = 'X';
	ft_strcpy(&new[2], str);
	*len += 2;
	ft_strdel(&str);
	all->flag_hash = 0;
	return (new);
}

/*
**After ft_ltoa_base the nb comes with capital letters ABCDEF, that is why
**X that can come if hash flag equals 1 is capital, so that after
**all the capital letters are changed
*/

void		do_lower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
