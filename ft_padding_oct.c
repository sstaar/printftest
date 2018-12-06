/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_oct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:12:52 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 15:12:09 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				put_o(char *nbr, int *par, char c, char conv)
{
	int		counter;

	counter = 0;
	while (par[1] == 2 && par[2]-- > 0 && c == ' ' && counter++ >= 0)
		ft_putchar(c);
	if (par[0] == 1 && conv == 'o' && counter++ >= 0)
		ft_putchar('0');
	else if (par[0] == 1 && (conv == 'x' || conv == 'X') && (counter += 2) >= 0)
	{
		ft_putchar('0');
		ft_putchar(conv);
	}
	while (par[1] == 2 && par[2]-- >= 0 && c == '0' && counter++ >= 0)
		ft_putchar(c);
	while (par[3]-- > 0 && counter++ >= 0)
		ft_putchar('0');
	ft_putstr(nbr);
	while (par[2]-- > 0 && par[1] == 1 && counter++ >= 0)
		ft_putchar(' ');
	return (counter + ft_strlen(nbr));
}

int				ft_padding_oct(uintmax_t  nbr, int *par, char c, char conv)
{
	char	*temp;
	int		size;

	temp = ft_strnew(0);
	if (nbr == 0 && (conv == 'x' || conv == 'X'))
		par[0] = 0;
	if (conv == 'o')
		temp = ft_putoct(nbr);
	else if (conv == 'u')
		temp = ft_uitoa(nbr);
	else if (conv == 'x' || conv == 'X')
		temp = ft_puthexa(nbr, conv - 23);
	if (par[3] == 0 && temp[0] == '0')
		temp = "";
	size  = ft_strlen(temp);
	if (par[0] == 1 && conv == 'o')
		size++;
	else if (par[0] == 1 && (conv == 'x' || conv == 'X'))
		size += 2;
	if (par[3] != -1)
		c = ' ';
	par[2] -= size;
	par[3] -= size;
	if (par[3] >= 0)
		par[2] -= par[3];
	return (put_o(temp, par, c, conv));
}
