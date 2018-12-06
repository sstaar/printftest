/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flt_ieee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:10:06 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 15:53:29 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*get_all(char *str, int ver, int ex)
{
	char	*temp;
	int		i;
	char	*fin;
	int		j;

	temp = multi_char(str, power_char("2", ex));
	i = ft_strlen(temp);
	fin = (char*)malloc(sizeof(char) * i + 1);
	j = -1;
	while (++j <= i - ver - 1)
		fin[j] = temp[j];
	fin[j] = '.';
	while (temp[j])
	{
		fin[j + 1] = temp[j];
		j++;
	}
	return(fin);
}

char		*get_all_neg(char *str, int ver, int ex)
{
	char	*fin;
	int		i;
	int		j;

	str = multi_char(str, power_char("5", ex));
	i = ft_strlen(str);
	fin = ft_strnew(ver + ex + 2);
	j = ver + ex + 1;
	while (--i >= 0)
		fin[j--] = str[i];
	while (j >= 2)
		fin[j--] = '0';
	fin[0] = '0';
	fin[1] = '.';
	return (fin);
}

char		*print_flt(char *str)
{
	int					i;
	char				*temp;

	temp = ft_strnew(1);
	temp[0] = '1';
	i = 8;
	while (++i < 32)
	{
		temp = multi1_char(temp, 10);
		if (str[i] == '1')
			temp = add_char(temp, power_char("5", i - 8));
	}
	i = bin_dic(str + 1, 8) - 127;
	if (i >= 0)
		temp = get_all(temp, ft_strlen(temp) - 1, i);
	else
		temp = get_all_neg(temp, ft_strlen(temp) - 1, -i);
	if (str[0] == '1')
		temp = ft_strjoin("-", temp);
	return(temp);
}

char		*get_flt_ieee(float nbr)
{
	int		n;
	int		i;
	char	*temp;

	temp = ft_strnew(0);
	i = 31;
	n = *(int*)(&nbr);
	while (i >= 0)
	{
		if (n >> i & 1)
			temp = ft_strjoin(temp, "1");
		else
			temp = ft_strjoin(temp, "0");
		i--;
	}
	ft_putendl(temp);
	return (print_flt(temp));
}
