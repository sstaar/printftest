/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_us.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:07:29 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/05 13:44:20 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_padding_ustr(unsigned int *str, int side, char c, int len)
{
	int		i;
	int		size;
	int		counter;

	counter = -1;
	i = -1;
	size = ft_voidlen((unsigned int*)str);
	//ft_putnbr(size);
	//ft_putendl("\n----------");
	if (side == 2)
		while (++i < len - size && ++ counter >= 0)
			ft_putchar(c);
	counter += ft_putustr(str) + 1;
	//counter += ft_voidlen((unsigned int*)str);
	if (side == 1)
		while (++i < len - size && ++counter >= 0)
			ft_putchar(c);
	return (counter);
}

int		treat_S(va_list *ap, t_info *info)
{
	int		side;
	int		fw;
	int		pre;
	unsigned int	*temp;

	fw = info->field_width;
	if (fw == -2)
		fw = va_arg(*ap, int);
	pre = info->precision;
	if (pre == -2)
		pre = va_arg(*ap, int);
	temp = va_arg(*ap, unsigned int*);
	if (!temp)
	{
		info->len = 6;
		ft_putstr("(null)");
		return (1);
	}
	temp = ft_voidndup(temp, pre);
	side = 2;
	if ((info->flag)[0] == 1)
		side = 1;
	info->len = ft_padding_ustr(temp, side, ' ', fw);
	return (1);
}
