/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:19:20 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/19 19:02:26 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_putpointer(unsigned long int point)
{
	char	*temp;
	char	temp2[2];

	temp2[1] = '\0';
	temp = ft_strnew(0);
	while (point != point * 16 && point != 0)
	{
		if (point % 16 > 9)
			temp2[0] = 'a' + (point % 16) % 10;
		else
			temp2[0] = '0' + point % 16;
		temp = ft_strjoin(temp2, temp);
		point /= 16;
	}
	return (temp);
}
