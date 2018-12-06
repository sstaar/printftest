/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:38:41 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/15 09:41:42 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnstr(char	*str, int n)
{
	int		i;

	i = -1;
	while (str[++i] && i < n)
		ft_putchar(str[i]);
}
