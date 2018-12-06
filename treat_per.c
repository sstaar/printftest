/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:46:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 16:44:30 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_padding_per(int side, char c, int len)
{
	int i;
	int	counter;

	counter = 0;
	i = -1;
	if (side == 2)
		while (++i < len - 1 && counter++ >= 0)
			ft_putchar(c);
	ft_putchar('%');
	if (side == 1)
		while (++i < len - 1 && counter++ >= 0)
			ft_putchar(c);
	return (++counter);
}

int			treat_per(va_list *ap, t_info *info)
{
	int		side;
	int		fw;

	fw = info->field_width;
	if (fw == -2)
		fw = va_arg(*ap, int);
	side = 2; 
	if ((info->flag)[0] == 1)
		side = 1;
	info->len = ft_padding_per(side, ' ', fw);
	return (1);
}
