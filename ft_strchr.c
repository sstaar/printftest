/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:10:27 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/04 20:10:29 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *i;

	i = 0;
	i = s;
	while (*s)
	{
		if (*s == c)
			return ((char*)i);
		s++;
		i++;
	}
	if (*s == c)
		return ((char*)i);
	return (NULL);
}
