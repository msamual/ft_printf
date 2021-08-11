/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:09:06 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:28:01 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				print_hexadecimal(t_tab *tab)
{
	unsigned long	n;
	unsigned int	len;
	char			*str;

	n = va_arg(tab->args, unsigned long);
	str = ft_itoa_hex(n, tab->convertion);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (tab->precision == 0 && str[0] == '0')
		str[0] = '\0';
	if (tab->precision > -1 && tab->precision >= (int)len)
		if (fill_zero(&str, len, tab->precision) == -1)
			return (-1);
	len = ft_strlen(str);
	if (tab->width > len)
		return (print_width_un(str, tab));
	else
	{
		ft_putstr(str);
		tab->res += len;
		free(str);
		return (0);
	}
}
