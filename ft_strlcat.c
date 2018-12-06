/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:50:25 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/06 16:50:28 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t i;
	size_t j;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	if (size - i == 0)
		return (size + s_len);
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (d_len + s_len);
}
