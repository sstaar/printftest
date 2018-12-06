/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:05:04 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/27 15:40:17 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_char(char *nbr1, char *nbr2)
{
	int		i;
	int		j;
	int		left[4];
	char	*temp;
	char	temp1[2];

	temp1[1] = '\0';
	left[0] = 0;
	temp = ft_strnew(0);
	i = ft_strlen(nbr1);
	j = ft_strlen(nbr2);
	if (i > j)
		left[3] = i;
	else
		left[3] = j;
	while (--left[3] >= 0)
	{
		if (--i < 0)
			left[1] = 0;
		else
			left[1] = nbr1[i] - '0';
		if (--j < 0)
			left[2] = 0;
		else
			left[2] = nbr2[j] - '0';
		left[0] += left[1] + left[2];
		temp1[0] = (left[0] % 10) + '0';
		left[0] /= 10;
		temp = ft_strjoin(temp1, temp);
	}
	if (left[0] > 0)
	{
		temp1[0] = (left[0] % 10) + '0';
		temp = ft_strjoin(temp1, temp);
	}
	return (temp);
}
