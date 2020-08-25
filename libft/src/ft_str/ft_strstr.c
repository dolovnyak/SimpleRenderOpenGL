/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:44:31 by sbecker           #+#    #+#             */
/*   Updated: 2018/11/29 09:38:05 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && haystack[i++] && needle[j++])
			{
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[k]);
		}
		k++;
		i = k;
		j = 0;
	}
	return (NULL);
}
