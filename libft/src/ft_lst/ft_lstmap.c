/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:58:37 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/05 19:44:28 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

static t_list	*ft_clean(t_list *list)
{
	ft_lstdel(&list, &ft_del);
	return (0);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f)
		return (0);
	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (0);
	new = f(new);
	begin = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew(lst->content, lst->content_size);
		if (!(new->next))
			return (ft_clean(begin));
		new->next = f(new->next);
		new = new->next;
	}
	return (begin);
}
