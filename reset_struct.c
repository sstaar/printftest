/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:39:20 by helbouaz          #+#    #+#             */
/*   Updated: 2018/11/29 17:42:14 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		reset_struct(t_info **info)
{
	((*info)->flag)[0] = 0;
	((*info)->flag)[1] = 0;
	((*info)->flag)[2] = 0;
	((*info)->flag)[3] = 0;
	((*info)->flag)[4] = 0;
	(*info)->field_width = -1;
	(*info)->precision = -1;
	(*info)->lenght_modifier = 0;
	(*info)->len = 0;
}
