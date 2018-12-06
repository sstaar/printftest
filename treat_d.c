/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:59:21 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/29 17:57:50 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		treat_mod(va_list *ap, t_info *info)
{
	long long	nbr;

	if (info->lenght_modifier == 1)
		nbr = va_arg(*ap, long);
	else if (info->lenght_modifier == 2)
		nbr = va_arg(*ap, long long);
	else
	{
		nbr = va_arg(*ap, int);
		if (info->lenght_modifier == 3)
			nbr = (short)nbr;
		else if (info->lenght_modifier == 4)
			nbr = (signed char)nbr;
	}
	return (nbr);
}

int			treat_d(va_list *ap, t_info *info)
{
	int		*sfwp;//0->side, 1->field width, 2->precision, 3->max
	char	*c;//0->to pad with, 1->to start with

	c = (char*)malloc(sizeof(char) * 2);
	sfwp = (int*)malloc(sizeof(int) * 4);
	sfwp[0] = 2;
	c[0] = ' ';
	c[1] = '\0';
	if ((info->flag)[0] == 1)
		sfwp[0] = 1;
	sfwp[1] = info->field_width;
	if (sfwp[1] == -2)
		sfwp[1] = va_arg(*ap, int);
	sfwp[2] = info->precision;
	if (sfwp[2] == -2)
		sfwp[2] = va_arg(*ap, int);
	if ((info->flag)[2] == 1)
		c[1] = ' ';
	if ((info->flag[1]) == 1)
		c[1] = '+';
	if ((info->flag)[3] == 1)
		c[0] = '0';
	if (sfwp[1] > sfwp[2])
		sfwp[4] = sfwp[1];
	else
		sfwp[4] = sfwp[2];
	info->len = ft_padding_nbr(treat_mod(ap, info), sfwp, c);
	free(c);
	free(sfwp);
	return (1);
}
