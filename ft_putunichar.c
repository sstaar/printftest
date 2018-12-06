/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunichar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:50:44 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 12:50:46 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunichar(char *str)
{
	unsigned char	c;
	int				counter;

	c = bin_dic(str, 8);
	write(1, &c, 1);
	counter = 1;
	if (str[8])
	{
		c = bin_dic(str + 8, 8);
		write(1, &c, 1);
		counter++;
	}
	if (str[16])
	{
		c = bin_dic(str + 16, 8);
		write(1, &c, 1);
		counter++;
	}
	if (str[24])
	{
		c = bin_dic(str + 24, 8);
		write(1, &c, 1);
		counter++;
	}
	return (counter);
}
