/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:06:09 by sbecker           #+#    #+#             */
/*   Updated: 2018/12/12 20:48:39 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle == haystack || *needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && k < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && haystack[i++] && needle[j++])
				;
			if (needle[j] == '\0' && i <= len + 1)
				return ((char *)&haystack[k]);
		}
		k++;
		i = k;
		j = 0;
	}
	return (NULL);
}
