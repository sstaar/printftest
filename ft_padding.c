/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:02:37 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/24 12:41:40 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_padding_str(char *str, int side, char c, int len)
{
	int		i;
	int		size;
	int		counter;
	
	counter = -1;
	i = -1;
	size = ft_strlen((char*)str);
	if (side == 2)
		while (++i < len - size && ++counter >= 0)
			ft_putchar(c);
	ft_putstr((char*)str);
	counter += ft_strlen((char*)str) + 1;
	if (side == 1)
		while (++i < len - size && ++counter >= 0)
			ft_putchar(c);
	return (counter);
}
