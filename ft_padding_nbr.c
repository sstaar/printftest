/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:53:21 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 17:35:15 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			padd_d(char *nbr, char *c, int *flag)
{
	int		counter;

	counter = 0;
	while (flag[0] == 2 && c[0] == ' ' && flag[1]-- > 0 && counter++ >= 0)
		ft_putchar(c[0]);
	//ft_putendl("++");
	if ((c[1] == ' ' || c[1] == '-' || c[1] == '+') && counter++ >= 0)
		ft_putchar(c[1]);
	while (flag[0] == 2 && c[0] == '0' && flag[1]-- > 0 && counter++ >= 0)
		ft_putchar(c[0]);
	while (flag[2]-- > 0 && counter++ >= 0)
		ft_putchar('0');
	ft_putstr(nbr);
	//ft_putendl("++");
	while (flag[0] == 1 && flag[1]-- > 0 && counter++ >= 0)
		ft_putchar(' ');
	return (counter + ft_strlen(nbr));
}

int			ft_padding_nbr(long long nbr, int *flag, char *c)
{
	char	*temp;
	int		i;
	int		size;

	i = -1;
	temp = ft_itoa(nbr);
	//ft_putendl("\n--------");
	//ft_putendl(temp);
	//ft_putendl("--------");
	if (temp[0] == '0' && flag[2] == 0)
		temp = "";
	if (nbr < 0)
	{
		temp++;
		c[1] = '-';
	}
	size = ft_strlen(temp);
	if (flag[2] != -1)
		c[0] = ' ';
	flag[1] -= size;
	flag[2] -= size;
	if (c[1] != '\0')
		flag[1]--;
	if (flag[2] >= 0)
		flag[1] -= flag[2];
	return(padd_d(temp, c, flag));
/*	if (flag[0] == 2)
		return (padd_left(temp, c, flag));
	else
		return (padd_right(temp, c, flag));*/
}
