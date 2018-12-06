/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:16:24 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/24 11:01:08 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_padding_ptr(unsigned long int add, int side, char *c, int *len)
{
	char	*temp;
	int		size;
	int		i;
	int		counter;

	temp = ft_putpointer(add);
	if (add == 0)
		temp = ft_strjoin(temp, "0");
	size = ft_strlen(temp);
	counter = 0;
	if (len[1] < size + 2)
		len[1] = size;
	i = -1;
	while (++i < len[0] - 2 - len[1] && counter++ >= 0)
		ft_putchar(' ');
	len[0] -= len[0] - len[1] - 2;	
	if (c[1] == '0' && (counter += 2) >= 0)
		ft_putstr("0x");
	i = -1;
	if (side == 2)
		while (++i < len[0] - size - 2 && counter++ >= 0)
			ft_putchar(c[1]);
	if (c[1] == ' ' && (counter += 2) >= 0)
		ft_putstr("0x");
	ft_putstr(temp);
	counter += ft_strlen(temp);
	if (side == 1)
		while (++i < len[0] - size - 2 && counter++ >= 0)
			ft_putchar(c[1]);
	return (counter);
}
