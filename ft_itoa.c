/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:24:10 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 14:08:24 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	lencal(long long n)
{
	size_t				len;
	unsigned long long	j;

	len = 0;
	j = n;
	if (n < 0)
	{
		j = -n;
		len++;
	}
	while (j > 9)
	{
		j /= 10;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa(long long n)
{
	char				*temp;
	unsigned long long	i;
	unsigned long long	j;

	i = lencal(n) - 1;
	if (!(temp = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	temp[i + 1] = '\0';
	j = n;
	if (n < 0)
	{
		j = -n;
		temp[0] = '-';
	}
	while (j > 9)
	{
		temp[i] = (j % 10) + '0';
		j /= 10;
		i--;
	}
	temp[i] = (j % 10) + '0';
	return (temp);
}

char			*ft_uitoa(unsigned long long n)
{
	char				*temp;
	char				temp2[2];

	temp2[1] = '\0';
	if (!(temp = ft_strnew(0)))
		return (NULL);
	while (n > 9)
	{
		temp2[0] = (n % 10) + '0';
		temp = ft_strjoin(temp2, temp);
		n /= 10;
	}
	temp2[0] = (n % 10) + '0';
	temp = ft_strjoin(temp2, temp);
	return (temp);
}
