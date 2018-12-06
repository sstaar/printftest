/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:27:17 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/06 10:27:20 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		nbr_words(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str[0] != '\0' && str[0] != c)
		count++;
	while (str[i])
	{
		if (i != 0)
			if (str[i] != c && str[i - 1] == c)
				count++;
		i++;
	}
	return (count);
}

static	int		nbr_letters(const char *str, char c)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			j;
	int			t;
	char		**temp;

	if (!(temp = (char**)malloc(sizeof(char*) * (nbr_words(s, c) + 1))))
		return (NULL);
	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			temp[t] = (char*)malloc(sizeof(char) * (nbr_letters(s + i, c) + 1));
			j = 0;
			while (s[i] && s[i] != c)
				temp[t][j++] = s[i++];
			temp[t++][j] = '\0';
		}
		else
			i++;
	}
	temp[t] = 0;
	return (temp);
}
