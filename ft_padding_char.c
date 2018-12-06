/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:39:54 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 12:32:13 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_padding_char(unsigned int main, int side, char c, int *len)
{
	int		i;
	int		counter;

	counter = 0;
	i = -1;
	if (side == 2)
		while (++i < len[0] - 1 && counter++ >= 0)
			ft_putchar(c);
	if (len[1] == 0 && counter++ >= 0)
		ft_putchar(main);
	else
		counter += ft_putuchar(main);
	if (side == 1)
		while (++i < len[0] - 1 && counter++ >= 0)
			ft_putchar(c);
	return (counter);
}
