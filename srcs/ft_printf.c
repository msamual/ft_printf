/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:48:33 by msamual           #+#    #+#             */
/*   Updated: 2020/11/12 18:48:36 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	t_tab	*tab;

	tab = (t_tab *)ft_calloc(sizeof(t_tab), 1);
	if (!tab)
		return (-1);
	tab->format = (char *)format;
	va_start(tab->args, format);
	while (format[tab->i])
	{
		if (format[tab->i] == '%')
		{
			clear(tab);
			parse(tab);
			if (execute(tab) == -1)
				return (-1);
		}
		else
		{
			ft_putchar(format[tab->i]);
			tab->res++;
		}
		tab->i++;
	}
	free(tab);
	return (tab->res);
}
