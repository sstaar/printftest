/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:12:29 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 15:08:49 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_putoct(uintmax_t  nbr)
{
	char	*temp;
	char	temp2[2];

	temp2[1] = '\0';
	temp = ft_strnew(0);
	while (nbr % 8 != nbr && nbr / 8 != 0)
	{
		temp2[0] = '0' + nbr % 8;
		temp = ft_strjoin(temp2, temp);
		nbr /= 8;
	}
	temp2[0] = '0' + nbr % 8;
	temp = ft_strjoin(temp2, temp);
	return (temp);
	free(temp);
}
