/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:33:47 by msamual           #+#    #+#             */
/*   Updated: 2020/11/11 11:49:07 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_percent(t_tab *tab)
{
	unsigned char c;
	unsigned char f;

	c = '%';
	f = 32;
	if (tab->width)
	{
		if (!(tab->toprint = (char *)ft_calloc(tab->width, sizeof(char))))
			return (-1);
		if (tab->zero && !tab->left)
			(f = 48);
		ft_memset(tab->toprint, f, tab->width);
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
