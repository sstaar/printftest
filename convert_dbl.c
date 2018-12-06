/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_dbl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:25:22 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/25 14:21:26 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*convert_dbl(double nbr)
{
	static char		*temp;
	int			i;

	i = 0;
	temp = ft_strnew(0);
	temp = ft_strjoin(dic_bin(nbr), temp);
	while (nbr > 1 && nbr - 1 >= 0)
		nbr--;
	temp = ft_strjoin(temp, ".");
	nbr *= 2;
	while (nbr > 0)
	{
		if (nbr < 1)
			temp = ft_strjoin(temp, "0");
		else if (nbr >= 1)
		{
			temp = ft_strjoin(temp, "1");
			nbr -= 1;
		}
		nbr *= 2;
	}
	return (temp);
}
