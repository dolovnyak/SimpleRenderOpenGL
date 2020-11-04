/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:30:00 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:30:50 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_with_error(const char **error_strs, int error_code)
{
	int i;

	if (!error_strs)
		exit(error_code);
	i = 0;
	while (error_strs[i])
	{
		ft_printf("%s ", error_strs[i]);
		i++;
	}
	ft_printf("\n");
	exit(error_code);
}
