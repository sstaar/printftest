/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:23:35 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 09:35:55 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		treat_s(va_list *ap, t_info *info)
{
	int		side;
	int		fw;
	int		pre;
	char		*temp;

	if (info->lenght_modifier == 1)
		return (treat_S(ap, info));
	fw = info->field_width;
	if (fw == -2)
		fw = va_arg(*ap, int);
	pre = info->precision;
	if (pre == -2)
		pre = va_arg(*ap, int);
	temp = va_arg(*ap, char*);
	if (!temp)
	{
		info->len = 6;
		ft_putstr("(null)");
		return (1);
	}
	temp = ft_strndup(temp, pre);
	side = 2;
	if ((info->flag)[0] == 1)
		side = 1;
	info->len = ft_padding_str(temp, side, ' ', fw);
	free(temp);
	return (1);
}
