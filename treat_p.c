/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:15:17 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/24 10:31:40 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		treat_p(va_list *ap, t_info *info)
{
	int		side;
	int		*fw;// 0->fw, 1->pres;
	char	*filler;//1->char to padd with, 0->char to use in the start

	filler = (char*)malloc(sizeof(char) * 2);
	fw = (int*)malloc(sizeof(int) * 2);
	filler[0] = '\0';
	side = 2;
	filler[1] = ' ';
	if ((info->flag)[0] == 1)
		side = 2;
	fw[0] = info->field_width;
	if (fw[0] == -2)
		fw[0] = va_arg(*ap, int);
	if ((info->flag)[2] == 1)
		filler[0] = ' ';
	if ((info->flag)[1] == 1)
		filler[0] = '+';
	if ((info->flag)[3] == 1)
		filler[1] = '0';
	fw[1] = info->precision;
	if (fw[1] == -2)
		fw[1] = va_arg(*ap, int);
	if (fw[1] > fw[0])
		filler[1] = '0';
	info->len = ft_padding_ptr(va_arg(*ap, unsigned long int), side, filler, fw);
	return (1);
}
