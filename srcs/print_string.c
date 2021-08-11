/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:26:41 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:26:55 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		width(t_tab *tab, unsigned int len, char *str)
{
	int		i;
	char	c;

	i = -1;
	c = ' ';
	tab->toprint = (char *)ft_calloc(tab->width + 1, sizeof(char));
	if (!tab->toprint)
		return (-1);
	if (tab->zero && !tab->left)
		c = '0';
	ft_memset(tab->toprint, c, tab->width);
	if (tab->left)
		while (str[++i])
			tab->toprint[i] = str[i];
	else
		while (len--)
			tab->toprint[--tab->width] = str[len];
	ft_putstr(tab->toprint);
	tab->res += ft_strlen(tab->toprint);
	return (0);
}

int		print_string(t_tab *tab)
{
	char				*str;
	unsigned int		len;
	int					res;

	res = 0;
	if (!(str = ft_strdup(va_arg(tab->args, char *))))
		str = ft_strdup("(null)");
	if (tab->precision > -1)
		str[tab->precision] = '\0';
	len = ft_strlen(str);
	if (tab->width && tab->width >= len)
		res = width(tab, len, str);
	else
	{
		ft_putstr(str);
		tab->res += len;
	}
	free(str);
	return (res);
}
