/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:37:07 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:27:40 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_width_un(char *str, t_tab *tab)
{
	int		i;
	char	c;

	if (!(tab->toprint = ft_calloc(tab->width + 1, sizeof(char))))
		return (-1);
	c = ' ';
	if (tab->zero && tab->precision == -1)
		c = '0';
	ft_memset(tab->toprint, ' ', tab->width);
	i = -1;
	if (tab->left)
		while (str[++i])
			tab->toprint[i] = str[i];
	else
	{
		ft_memset(tab->toprint, c, tab->width);
		i = ft_strlen(str);
		while (i)
			tab->toprint[--tab->width] = str[--i];
	}
	free(str);
	ft_putstr(tab->toprint);
	tab->res += ft_strlen(tab->toprint);
	return (0);
}

int		print_unsigned(t_tab *tab)
{
	unsigned int	nb;
	unsigned int	len;
	char			*str;

	nb = va_arg(tab->args, unsigned int);
	str = ft_itoa_unsigned(nb);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (tab->precision == 0 && nb == 0)
		str[0] = '\0';
	else if (tab->precision > -1 && tab->precision > (int)len)
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
	return (0);
}
