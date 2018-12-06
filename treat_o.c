/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:26:50 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 14:21:12 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		treat_mod_o(va_list *ap, t_info *info)
{
	unsigned long long	nbr;

	if (info->lenght_modifier == 1)
		nbr = (unsigned long)va_arg(*ap, unsigned long);
	else if (info->lenght_modifier == 2)
		nbr = (unsigned long long)va_arg(*ap, unsigned long long);
	else 
	{
		nbr = va_arg(*ap, int);
		if (info->lenght_modifier == 3)
			nbr = (unsigned short)nbr;
		else if (info->lenght_modifier == 4)
			nbr = (unsigned char)nbr;
	}
	return (nbr);
}

unsigned long long		treat_mod_u(va_list *ap, t_info *info)
{
	unsigned long long	nbr;

	if (info->lenght_modifier == 1)
		nbr = va_arg(*ap, unsigned long);
	else if (info->lenght_modifier == 2)
	{
		nbr = va_arg(*ap, unsigned long long);
	}
	else 
	{
		nbr = va_arg(*ap, unsigned int);
		if (info->lenght_modifier == 3)
			nbr = (unsigned short)nbr;
		else if (info->lenght_modifier == 4)
			nbr = (unsigned char)nbr;
	}
	return (nbr);
}

int						treat_ou(va_list *ap, t_info *info, char conv)
{
	int			*par;//0-># present, 1->side, 2->field width, 3->precision
	char		c;//to pad with

	par = (int*)malloc(sizeof(int) * 4);
	par[0] = 0;
	if ((info->flag)[4] == 1 && (conv == 'o' || conv == 'x' || conv == 'X'))
		par[0] = 1;
	par[1] = 2;
	if ((info->flag)[0] == 1)
		par[1] = 1;
	par[2] = info->field_width;
	if (par[2] == -2)
		par[2] = va_arg(*ap, int);
	par[3] = info->precision;
	if (par[3] == -2)
		par[3] = va_arg(*ap, int);
	c = ' ';
	if ((info->flag)[3] == 1)
		c = '0';
	if (conv == 'o')
		info->len = ft_padding_oct(treat_mod_o(ap, info), par, c, conv);
	else if (conv == 'u')
		info->len = ft_padding_oct(treat_mod_u(ap, info), par, c, conv);
	else if (conv == 'x' || conv == 'X')
		info->len = ft_padding_oct(treat_mod_u(ap, info), par, c, conv);
	return (1);
}
