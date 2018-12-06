/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:24:21 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/26 12:26:40 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		power_of(long long nbr, int power)
{
	long long	temp;
	int 		i;

	i = -1;
	temp = 1;
	while (++i < power)
		temp *= nbr;
	return (temp);
}
