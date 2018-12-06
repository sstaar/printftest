/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:12:24 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 08:59:22 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*treat_mod_f(va_list *ap, t_info *info)
{
	char	*temp;

	if (info->lenght_modifier == 5)
		temp = get_dbl_ieee(va_arg(*ap, long double));
	else
		temp = get_dbl_ieee(va_arg(*ap, double));
	return (temp);
}

int			put_f(char *nbr, int *par, char *c)
{
	int			i;
	int			counter;

	i = -1;
	counter = 0;
	while (c[0] == ' ' && par[0] == 2 && --par[1] >= 0 && counter++ >= 0)
		ft_putchar(' ');
	if (c[1] != '\0' && counter++ >= 0)
		ft_putchar(c[1]);
	while (c[0] == '0' && par[0] == 2 && --par[1] >= 0 && counter++ >= 0)
		ft_putchar('0');
	while (++i < par[2] && nbr[i] && counter++ >= 0)
		ft_putchar(nbr[i]);
	while (i++ < par[2] && counter++ >= 0)
		ft_putchar('0');
	while (par[0] == 1 && --par[1] >= 0 && counter++ >= 0)
		ft_putchar(' ');
	return (counter);
}

char		*rounding(char *nbr, int ver)
{
	char	*temp;
	int		i;
	int		v;

	temp = (char*)malloc(sizeof(char) * ft_strlen(nbr) + ver + 1);
	i = -1;
	while (nbr[++i] && nbr[i] != '.')
		temp[i] = nbr[i];
	v = 0;
	while (nbr[++i] && v++ < ver + 1)
		temp[i - 1] = nbr[i];
	temp[i] = '\0';
	temp = add_char(temp, "1");
	i = ft_strlen(temp);
	if (i < ver)
		return (nbr);
	temp = ft_strjoin(ft_strsub(temp, 0, i - ver - 1),
			ft_strjoin(".", ft_strsub(temp, i - ver - 1, ver)));
	return (temp);
}

int			ft_padding_ver(char *nbr, int *par, char *c)
{
	int			size;
	int			i;

	if (nbr[0] == '-' && ++nbr)
		c[1] = '-';
	i = -1;
	size = 0;
	nbr = rounding(nbr, par[2]);
	while (nbr[++i] && nbr[i] != '.')
		size++;
	size += par[2];
	if (par[2] == 0 && par[3] == 1)
		size++;
	else if (par[2] != 0)
		size++;
	par[1] -= size;
	if (c[1] != '\0')
		par[1]--;
	par[2] = size;
	return (put_f(nbr, par, c));
}

int			treat_f(va_list *ap, t_info *info)
{
	int			*par;
	char		*c;

	par = (int*)malloc(sizeof(int) * 4);
	c = (char*)malloc(sizeof(char) * 2);
	par[0] = 2;
	c[0] = ' ';
	par[3] = 0;
	if ((info->flag)[4] == 1)
		par[3] = 1;
	if ((info->flag)[0] == 1)
		par[0] = 1;
	c[1] = '\0';
	if ((info->flag)[2] == 1)
		c[1] = ' ';
	if ((info->flag)[1] == 1)
		c[1] = '+';
	par[1] = info->field_width;
	if (par[1] == -2)
		par[1] = va_arg(*ap, int);
	par[2] = info->precision;
	if (par[2] == -2)
		par[2] = va_arg(*ap, int);
	else if (par[2] == -1)
		par[2] = 6;
	if ((info->flag)[3] == 1)
		c[0] = '0';
	info->len = ft_padding_ver(treat_mod_f(ap, info), par, c);
	return (1);
}
