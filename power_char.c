/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:27:50 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 15:55:28 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*power_char(char *nbr1, int nbr2)
{
	int			i;
	char		*temp;

	temp = ft_strnew(0);
	if (nbr2 > 0)
	{
		temp = nbr1;
		i = -1;
		while (++i < nbr2 - 1)
			temp = multi_char(temp, nbr1);
	}
	else if (nbr2 == 0)
		return ("1");
	return (temp);
}
