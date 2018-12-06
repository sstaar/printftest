/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:55:22 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/09 09:59:45 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && temp1[i] == temp2[i])
		i++;
	if (i == n)
		i--;
	return (temp1[i] - temp2[i]);
}
