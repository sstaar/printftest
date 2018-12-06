/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helbouaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:55:05 by helbouaz          #+#    #+#             */
/*   Updated: 2018/12/06 15:18:29 by helbouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <locale.h>

int			check_if_start(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == '#' || c == '+' || c == '-' || c == '0' || c == 'h' ||
			c == 'l' || c == 'L' || (c >= '0' && c <= '9') || c == '.' ||
			c == '*' || c == ' ' || c == 'S' || c == 'C' || c == 'D' ||
			c == 'O' || c == 'U' || c == '%' || c == 'z' || c == 'j')
		return (1);
	else
		return (0);
}

int			check_if_space(char *str)
{
	if (str[1] && str[2] && str[3] && str[4] && str[0] == 's' && str[1] == 'p' &&
			str[2] == 'a' && str[3] == 'c' && str[4] == 'e')
		return (1);
	else
		return (0);
}

int			check_flags(char *str, t_info **info)
{
	if (str[0] == '+')
	{
		((*info)->flag)[1] = 1;
		return (1);
	}
	else if (str[0] == '-')
	{
		((*info)->flag)[0] = 1;
		return (1);
	}
	else if (str[0] == ' ')
	{
		((*info)->flag)[2] = 1;
		return (1);
	}
	else if (str[0] == '0')
	{
		((*info)->flag)[3] = 1;
		return (1);
	}
	else if (str[0] == '#')
	{
		((*info)->flag)[4] = 1;
		return (1);
	}
	else 
		return (0);
}

int			check_field_width(char *str, t_info **info)
{

	if (str[0] >= '0' && str[0] <= '9')
	{
		(*info)->field_width = ft_atoi(str);
		return (ft_strlen(ft_itoa((*info)->field_width)));
	}
	else if (str[0] == '*')
	{
		(*info)->field_width = -2;
		return (1);
	}
	else
	{
		(*info)->field_width = -1;
		return (0);
	}
}

int			check_precision(char *str, t_info **info)
{
	if (str[0] == '.' && str[1] != '*' && str[1] >= '0' && str[1] <= '9')
	{
		(*info)->precision = ft_atoi(str + 1);
		return (ft_strlen(ft_itoa((*info)->precision))  + 1);
	}
	else if (str[0] == '.' && str[1] == '*')
	{
		(*info)->precision = -2;
		return (2);
	}
	else if (str[0] == '.')
	{
		(*info)->precision = 0;
		return (1);
	}
	else
	{
		(*info)->precision = -1;
		return (0);
	}
}

int			check_lenght_modifier(char *str, t_info **info)
{
	if (str[0] == 'l' && (!str[1] || str[1] != 'l'))
	{
		(*info)->lenght_modifier = 1;
		return (1);
	}
	else if (str[0] == 'l' && str[1] && str[1] == 'l')
	{
		(*info)->lenght_modifier = 2;
		return (2);
	}
	else if (str[0] == 'h' && (!str[1] || str[1] != 'h'))
	{
		(*info)->lenght_modifier = 3;
		return (1);
	}
	else if (str[0] == 'h' && str[1] && str[1] == 'h')
	{
		(*info)->lenght_modifier = 4;
		return (2);
	}
	else if (str[0] == 'L')
	{
		(*info)->lenght_modifier = 5;
		return (1);
	}
	else if (str[0] == 'j')
	{
		(*info)->lenght_modifier = 6;
		return (1);
	}
	else if (str[0] == 'z')
	{
		(*info)->lenght_modifier = 7;
		return (1);
	}
	else
	{
		(*info)->lenght_modifier = 0;
		return (0);
	}
}

int			apply(va_list *ap, char *str, t_info *info)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (treat_d(ap, info));
	if (str[0] == 'D')
	{
		info->lenght_modifier = 1;
		return (treat_d(ap, info));
	}
	else if (str[0] == 's')
		return (treat_s(ap, info));
	else if (str[0] == 'S')
	{
		return (treat_S(ap, info));
	}
	else if (str[0] == 'c')
		return (treat_c(ap, info));
	else if (str[0] == 'C')
	{
		info->lenght_modifier = 1;
		return (treat_c(ap, info));
	}
	else if (str[0] == 'o' || str[0] == 'u')
		return (treat_ou(ap, info, str[0]));
	else if (str[0] == 'O' || str[0] == 'U')
	{
		info->lenght_modifier = 1;
		return (treat_ou(ap, info, str[0] + ('a' - 'A')));
	}
	else if (str[0] == 'x' || str[0] == 'X')
		return (treat_ou(ap, info, str[0]));
	else if (str[0] == 'p')
		return (treat_p(ap, info));
	else if (str[0] == 'f')
		return (treat_f(ap, info));
	else if (str[0] == '%')
		return (treat_per(ap, info));
	return (0);
}

int			treat(va_list *ap, char *str, t_info **info)
{
	int			i;

	i = 0;
	//ft_putnbr((info->flag)[0]);
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ' ||
			str[i] == '#' || str[i] == '0')
		i += check_flags(str + i, info);
	i += check_field_width(str + i, info);
	i += check_precision(str + i, info);
	i += check_lenght_modifier(str + i, info);
	i += apply(ap, str + i, *info);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	t_info		*info;
	va_list		ap;
	int			i;
	int			count;

	count = 0;
	va_start(ap, str);
	i = 0;
	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (0);
	while (str[i])
	{
		/*if (str[i] == '%' && str[i + 1] && str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
			count++;
		}*/
		if (str[i] == '%' && str[i + 1] && !check_if_start(str[i + 1]))
		{
			i++;
		}
		else if (str[i] == '%' && !str[i + 1])
			break ;
		else if (str[i] == '%' && str[i + 1] && check_if_start(str[i + 1]))
		{
			reset_struct(&info);
			//ft_putnbr(info->flag[2]);
			//ft_putendl("-----------------");
			i += treat(&ap, (char*)(str + i + 1), &info) + 1;
			count += info->len;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
/*
int			main(int argc, char **argv)
{
	setlocale(LC_ALL,"");
	float i = 0.04;
	//char	*S = "Hamza El Bouazizi";
	//int		i = ft_atoi("55d.");
	//ft_printf("%+5.8lld");
	//ft_putoct(54557);
	//ft_puthexa(9999, 'A');
	//ft_printf("%2.9p", 1234);
	//printf("\n%010.5d", 123);
	//ft_printf("%hd", INT_MAX - 2);
	//printf("\n%hd", INT_MAX - 2);
	//ft_putchar('\n');
	//ft_putnbr(ft_atoi(ft_itoa(LLONG_MAX)));
	//ft_putoct(50);
	//printf("%+o", 55);
	//printf("");
	//printf("\ntest : %5d\n%d", 5, 6);
	//printf("\n%#-10.1u", 55);
	//ft_printf("%#.x", 0);
	//printf("\n%#.x", 0);
	//ft_printf("%o", 2500);
	//ft_printf("%#08x", 42);
	//printf("\n%#08x", 42);
	//ft_printf("%#6o", 2500);
	//printf("\n%#6o", 2500);
	//ft_printf("%d %d %d", -42, 42, 13);
	//ft_printf("%d %d %d %d", 1, -4, 33, 42);
	//ft_printf("%lu", -42);
	//printf("\n%lu", -42);
	//ft_putnbr(ft_printf("% Z ", "test"));
	//ft_putchar('\n');
	//ft_putnbr(printf("% Z ", "test"));
	//ft_printf("%#.o\n", 0);
	//printf("%#x", 0);
	//ft_putstr(convert_dbl(35.6));
	//printf("\n%.30f", 35.6);
	//minu_char("100", "49");
	//ft_putendl(add_char("10000000005415151654120000054520000000", "1234565656565565656678912345678911"));
	//ft_printf("%c --> %c",'X','Y');
	//printf("%.50f", 2.1);
	//ft_putstr(multi_char("25", 5));
	//ft_putstr(power_char(5, 69));
	//printf("test");
	//ft_putendl(power);
	//get_flt_ieee(697.26);
	//ft_putendl(power_char("2", 8));
	//ft_putendl(multi_char("37218749523162841796875", "256"));
	//ft_putendl(multi_char("0", "3"));
	//ft_printf("%c -> %*s",'X',12,"HAmza");
	//printf("%.25f\n", 0.004);
	//long double t = 1.5;
	//ft_putendl(get_dbl_ieee(999999999999.999999999999));
	//printf("\n%.100Lf", t);
	//printf("%.100f", i);
	//printf("%lu", sizeof(long double));
	//printf(argv[1], 555.2);
	//float t = -14.99;
	//ft_printf("%.10f", t);
	//printf("\n%.1f", t);
	//ft_printf("%d %d %d %d", 1, -2, 33, 42);
	//ft_printf("%d %d %d %d", 1, -2, 33, 42);
	//printf(argv[1]);
	//printf("%S", L"bdfxhjvbdzxngb");
	//ft_printf("%u", -1);
	//printf("\n%u", -1);
	//get_flt_ieee(5.6);
	//ft_putendl(add_char("2220446049250313080847263336181640625", "2220446049250313080847263336181640625"));
	//printf("%zd", 4440892098500626161694526672363281250 + 4440892098500626161694526672363281250);
	//double t = 0.004;
	//ft_printf("%.20f", t);
	//printf("\n%.20f", t);
	//double t = 5.678;
	//ft_printf("%S", L"Á±≥");
	ft_putnbr(ft_printf("%15.4S", L"我是一只猫。"));
	//printf("\n%lf", t);
	//char	*test;
	//test = "teeest";
	//ft_putendl(test);
	return (0);
}*/
