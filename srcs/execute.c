/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:45:14 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:14:44 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_char(t_tab *tab)
{
	unsigned char c;

	c = va_arg(tab->args, int);
	if (tab->width)
	{
		if (!(tab->toprint = (char *)ft_calloc(tab->width, sizeof(char))))
			return (-1);
		ft_memset(tab->toprint, ' ', tab->width);
		if (tab->left)
			tab->toprint[0] = c;
		else
			tab->toprint[tab->width - 1] = c;
		putstr_width(tab->toprint, tab->width);
		tab->res += tab->width;
	}
	else
	{
		ft_putchar(c);
		tab->res++;
	}
	return (0);
}

int		execute(t_tab *tab)
{
	int res;

	res = 0;
	if (tab->convertion == 0)
		res = print_char(tab);
	if (tab->convertion == 1)
		res = print_string(tab);
	if (tab->convertion == 2)
		res = print_pointer(tab);
	if (tab->convertion == 3 || tab->convertion == 4)
		res = print_decimal(tab);
	if (tab->convertion == 5)
		res = print_unsigned(tab);
	if (tab->convertion == 6 || tab->convertion == 7)
		res = print_hexadecimal(tab);
	if (tab->convertion == 8)
		res = print_percent(tab);
	free(tab->toprint);
	if (tab->convertion == -1)
	{
		tab->i--;
		return (0);
	}
	return (res);
}
