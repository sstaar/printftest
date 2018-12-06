/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:07:34 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/05 16:07:36 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char*)ft_strndup(src, len);
	temp2 = (unsigned char*)dst;
	i = 0;
	while (i < len)
	{
		*(temp2 + i) = *(temp1 + i);
		i++;
	}
	return (dst);
}
