/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:46:07 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/23 17:35:28 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			treat_c(va_list *ap, t_info *info)
{
	unsigned int	temp;
	int		side;
	int		*fw;

	fw = (int*)malloc(sizeof(int) * 2);
	fw[0] = info->field_width;
	fw[1] = 0;
	if (fw[0] == -2)
		fw[0] = va_arg(*ap, int);
	if (info->lenght_modifier == 1)
	{
		temp = va_arg(*ap, unsigned int);
		fw[1] = 1;
	}
	else
		temp = (char)va_arg(*ap, unsigned int);
	side = 2; 
	if ((info->flag)[0] == 1)
		side = 1;
	info->len = ft_padding_char(temp, side, ' ', fw);
	return (1);
}
