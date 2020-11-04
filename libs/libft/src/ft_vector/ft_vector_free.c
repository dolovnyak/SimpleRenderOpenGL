/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:35:56 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:38:29 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_free(t_vector *vector)
{
	if (vector->size == 0 || vector->elems_data == NULL)
		return ;
	free(vector->elems_data);
	vector->elem_size = 0;
	vector->size = 0;
}
