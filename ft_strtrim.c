/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 09:27:20 by helbouaz          #+#    #+#             */
/*   Updated: 2018/10/06 09:27:22 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*temp;

	beg = 0;
	end = 0;
	i = -1;
	while (s[++i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		beg++;
	i = ft_strlen(s);
	while (--i && i > beg && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		end++;
	if (!(temp = (char*)malloc(sizeof(char) *
		(ft_strlen(s) - end - beg + 1))))
		return (NULL);
	i = 0;
	while (beg < ft_strlen(s) - end)
		temp[i++] = s[beg++];
	temp[i] = '\0';
	return (temp);
}
