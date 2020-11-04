/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:36:28 by sbecker           #+#    #+#             */
/*   Updated: 2020/10/29 22:37:59 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vector_create(size_t elem_size)
{
	t_vector	vector;

	vector.elem_size = elem_size;
	vector.size = 0;
	vector.elems_data = NULL;
	return (vector);
}
