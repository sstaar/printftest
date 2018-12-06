/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:01:00 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/06 14:01:01 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char*)ft_strdup(src);
	temp2 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*(temp2 + i) = temp[i];
		if (*(temp2 + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
