/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:37:56 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/27 16:38:33 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*multi1_char(char *nbr1, int nbr2)
{
	int		i;
	char	*temp;

	if (nbr1[0] == '0' || nbr2 == 0)
		return ("0");
	i = -1;
	temp = ft_strdup(nbr1);
	while (++i < nbr2 - 1)
		temp = add_char(temp, nbr1);
	return (temp);
}

char		*multi_char(char *nbr1, char *nbr2)
{
	int			i;
	char		*temp;
	int			j;
	char		*temp1;
	int			t;

	temp = ft_strnew(1);
	temp[0] = '0';
	j = 0;
	i = ft_strlen(nbr2);
	while (--i >= 0)
	{
		//ft_putendl(temp);
		t = -1;
		//ft_putchar(nbr2[i]);
		temp1 = multi1_char(nbr1, nbr2[i] - '0');
		//ft_putendl(temp1);
		while (++t < j)
			temp1 = ft_strjoin(temp1, "0");
		//ft_putendl(temp1);
		//ft_putendl("--------------------------------");
		temp = add_char(temp, temp1);
		j++;
	}

	/*int		i;
	int		j;
	char	*temp;
	int		n;
	int		t;

	temp = ft_strnew(1);
	temp[0] = '0';
	i = -1;
	n = ft_strlen(nbr2);
	j = n;
	while (++i < n)
	{
		//ft_putendl( multi1_char(nbr1, nbr2[i] - '0'));
		//ft_putnbr(10 * (j -1));
		//ft_putendl("---------------------------------");
		//temp = multi_char(temp, power_char("10", --j));
		t = -1;
		ft_putendl(temp);
		while (++t < j)
			temp = ft_strjoin(temp, "0");
		ft_putendl(temp);
		ft_putendl(multi1_char(nbr1, nbr2[i] - '0'));
		ft_putendl("---------------------------------");
		j--;
		temp = add_char(temp, multi1_char(nbr1, nbr2[i] - '0'));
		//ft_putendl(nbr2);
	}*/
	return (temp);
}
