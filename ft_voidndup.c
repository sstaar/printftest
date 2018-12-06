/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:56:58 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 13:44:06 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					nbr_bytes(unsigned int c)
{
	int		i;

	i = ft_strlen(dic_bin(c));
	if (i >= 1 && i <= 7)
		return (1);
	else if (i >= 8 && i <= 11)
		return (2);
	else if (i >= 12 && i <= 16)
		return (3);
	else if (i >= 17 && i <= 21)
		return (4);
	return (0);
}

unsigned int		*ft_voidndup(unsigned int *src, int len)
{
	int				i;
	unsigned int	*temp;
	int				counter;

	counter = 0;
	if (len < 0)
		len = ft_voidlen(src);
	if (!(temp = (unsigned int*)malloc(sizeof(unsigned int) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len && src[i])
	{
		//ft_putnbr(counter);
		//ft_putendl("\n------------");
		temp[i] = src[i];
		counter += nbr_bytes(src[i]);
		if (counter > len)
			break ;
	}
	while (i++ <= len)
		temp[i - 1] = 0;
	return (temp);
}
