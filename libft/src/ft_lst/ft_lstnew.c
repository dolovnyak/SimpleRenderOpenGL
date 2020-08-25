/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:34:04 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/05 17:48:38 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	if (!list)
		return (0);
	if (!content)
	{
		list->content = 0;
		list->content_size = 0;
	}
	else
	{
		list->content = malloc(content_size);
		if (!list->content)
			return (0);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = 0;
	return (list);
}
