/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:53:13 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 12:21:21 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*four_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("11110...10......10......10......", temp);
	j = 31;
	while (j > 25)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 17)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 9)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 4 && src[i - 1])
		temp[j--] = src[--i];
	while (j >= 0)
	{
		if (temp[j] != '.')
			break ;
		else
			temp[j] = '0';
		j--;
	}
	return (temp);

}

char			*three_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("1110....10......10......", temp);
	j = 23;
	while (j > 17)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 9)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 3 && src[i - 1])
		temp[j--] = src[--i];
	while (j >= 0)
	{
		if (temp[j] != '.')
			break ;
		else
			temp[j] = '0';
		j--;
	}
	return (temp);
}

char			*two_bytes(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	temp = ft_strnew(0);
	temp = ft_strjoin("110.....10......", temp);
	j = 15;
	while (j > 9)
		temp[j--] = src[--i];
	j -= 2;
	while (j > 2 && src[i])
		temp[j--] = src[--i];
	while (j-- > 0)
		if (temp[j] == '.')
			temp[j] = '0';
	return (temp);
}
/* 
char			*one_byte(char **str)
{
	char		*temp;
	char		*src;
	int			i;
	int			j;

	src = *str;
	i = ft_strlen(src);
	j = 7;
	temp = ft_strnew(0);
	temp = ft_strjoin("0.......", temp);
	while (j > 0)
		temp[j--] = src[--i];
	while (j >= 0)
		temp[j--] = '0';
	return (temp);
}
*/
int			ft_putuchar(unsigned int i)
{
	char	*temp;
	int		size;

	temp = dic_bin(i);
	size = ft_strlen(temp);
	if (size >= 1 && size <= 7)
	{
		ft_putchar(i);
		return (1);
	}
	else if (size >= 8 && size <= 11)
	{
		temp = two_bytes(&temp);
		return (ft_putunichar(temp));
	}
	else if (size >= 12 && size <= 16)
	{
		temp = three_bytes(&temp);
		return (ft_putunichar(temp));
	}
	else if (size >= 17 && size <= 21)
	{
		temp = four_bytes(&temp);
		return (ft_putunichar(temp));
	}
	return (0);
}
