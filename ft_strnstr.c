/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 10:00:09 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/05 10:00:11 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		checker(const char *s1, const char *s2, const int i, size_t len)
{
	size_t check;
	size_t k;
	size_t j;
	size_t t;

	check = 1;
	k = i;
	j = 0;
	t = 0;
	while (s1[k] && s2[j])
	{
		if (s1[k] != s2[j])
			return (0);
		k++;
		j++;
	}
	if (k > len)
		return (0);
	if (!s1[k] && s2[j])
		return (0);
	return (check);
}

char			*ft_strnstr(const char *haystack,
	const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	j = 0;
	while (*(haystack + i) && j < len)
	{
		if (*(haystack + i) == *needle)
		{
			if (checker(haystack, needle, i, len) == 1)
				return ((char*)(haystack + i));
		}
		i++;
		j++;
	}
	return (NULL);
}
