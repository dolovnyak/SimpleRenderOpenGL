/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jtoc_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:46:35 by sbednar           #+#    #+#             */
/*   Updated: 2019/06/05 23:38:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libjtoc.h"

static int	str_hash(const char *str)
{
	int	res;
	int	p;
	int	i;

	res = 0;
	p = 1;
	i = -1;
	while (str[++i])
	{
		res = (res + (str[i] - 'a') * p) % HASH_M;
		p = (p * HASH_P) % HASH_M;
	}
	return (res);
}

t_jnode		*jtoc_node_create(enum e_type type, char *name, void *data)
{
	t_jnode	*res;

	if (!(res = (t_jnode *)malloc(sizeof(t_jnode))))
		return (NULL);
	res->type = type;
	res->name = ft_strdup(name);
	res->hash = str_hash(name);
	res->data = data;
	res->right = NULL;
	res->down = NULL;
	return (res);
}

void		jtoc_node_add_child(t_jnode *parent, t_jnode *child)
{
	t_jnode	*cur;

	if (!(parent->down))
	{
		parent->down = child;
		return ;
	}
	cur = parent->down;
	while (cur->right)
		cur = cur->right;
	cur->right = child;
}

int	split_str_before_after_dot(const char *src, char **before_dot, char **after_dot)
{
	int	i;
	int	len;

	i = -1;
	while (src[++i])
	{
		if (src[i] == '.')
		{
			*before_dot = (char *)ft_memalloc(sizeof(char) * (i + 1));
			ft_strncpy(*before_dot, src, i);
			len = ft_strlen(&src[++i]);
			*after_dot = (char *)ft_memalloc(sizeof(char) * (len + 1));
			ft_strncpy(*after_dot, &src[i], len);
			return (1);
		}
	}
	return (0);
}

t_jnode	*jtoc_node_get_by_path(t_jnode *parent, const char *path)
{
	t_jnode	*cur;
	char	*path_before_dot;
	char	*path_after_dot;

	if (!path || !(*path) || !parent)
		return (NULL);
	cur = parent->down;
	if (!ft_strchr(path, '.'))
		while (cur)
		{
			if (ft_strcmp(cur->name, path) == 0)
				return cur;
			cur = cur->right;
		}
	else
	{
		split_str_before_after_dot(path, &path_before_dot, &path_after_dot);
		while (cur)
		{
			if (ft_strcmp(cur->name, path_before_dot) == 0)
			{
				free(path_before_dot);
				cur = jtoc_node_get_by_path(cur, path_after_dot);
				free(path_after_dot);
				return (cur);
			}
			cur = cur->right;
		}
	}
	return NULL;
}

void		jtoc_node_clear(t_jnode *cur)
{
	if (cur->right)
		jtoc_node_clear(cur->right);
	if (cur->down)
		jtoc_node_clear(cur->down);
	free(cur->data);
	free(cur->name);
	free(cur);
}
