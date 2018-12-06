/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:27:13 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/24 11:25:01 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_puthexa(unsigned long long  nbr, char c)
{
	char	*temp;
	char	temp2[2];

	temp = ft_strnew(0);
	temp2[1] = '\0';
	if (nbr == 0)
		temp = ft_strjoin("0", temp);
	while (nbr != nbr * 16 && nbr != 0)
	{
		if (nbr % 16 > 9)
			temp2[0] = c + (nbr % 16) % 10;
		else
			temp2[0] = '0' + nbr % 16;
		temp = ft_strjoin(temp2, temp);
		nbr /= 16;
	}
	return(temp);
	free(temp);
}
