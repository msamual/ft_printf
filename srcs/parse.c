/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:37:09 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:39:14 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				intlen(t_tab *tab)
{
	int len;

	len = 0;
	while (ft_isdigit(tab->format[tab->i + len]))
		len++;
	return (len);
}

unsigned int	mod(int n, t_tab *tab)
{
	if (n < 0)
	{
		tab->left = 1;
		return (-n);
	}
	return (n);
}

void			parse_convertion(t_tab *tab)
{
	char	*convs;
	int		i;

	i = 0;
	convs = "cspdiuxX%";
	while (convs[i])
	{
		if (tab->format[tab->i] == convs[i])
		{
			tab->convertion = i;
			return ;
		}
		i++;
	}
	tab->convertion = -1;
}

void			parse_precision(t_tab *tab)
{
	tab->i++;
	if (ft_isdigit(tab->format[tab->i]))
	{
		tab->precision = ft_atoi(&(tab->format[tab->i]));
		tab->i += intlen(tab);
	}
	else if (tab->format[tab->i] == '*')
	{
		while (tab->format[tab->i] == '*')
		{
			tab->precision = va_arg(tab->args, int);
			tab->i++;
		}
	}
	else
		tab->precision = 0;
}

void			parse(t_tab *tab)
{
	tab->i++;
	while (tab->format[tab->i] == '0' || tab->format[tab->i] == '-' ||
			tab->format[tab->i] == '*')
	{
		if (tab->format[tab->i] == '0')
			tab->zero = 1;
		else if (tab->format[tab->i] == '-')
			tab->left = 1;
		else if (tab->format[tab->i] == '*')
			tab->width = mod(va_arg(tab->args, int), tab);
		tab->i++;
	}
	if (ft_isdigit(tab->format[tab->i]))
	{
		tab->width = ft_atoi(&(tab->format[tab->i]));
		tab->i += intlen(tab);
	}
	while (tab->format[tab->i] == '.')
		parse_precision(tab);
	parse_convertion(tab);
}
