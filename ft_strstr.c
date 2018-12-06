/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:08:31 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/05 09:08:39 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		checker(const char *s1, const char *s2, const int i)
{
	int k;
	int j;

	k = i;
	j = 0;
	while (s1[k] && s2[j])
	{
		if (s1[k] != s2[j])
			return (0);
		k++;
		j++;
	}
	if (!s1[k] && s2[j])
		return (0);
	return (1);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (*(haystack + i))
	{
		if (*(haystack + i) == *needle)
		{
			if (checker(haystack, needle, i) == 1)
				return ((char*)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
