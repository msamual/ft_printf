/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:07:44 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:27:11 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_width(char *str, t_tab *tab)
{
	int		i;
	char	c;

	if (!(tab->toprint = ft_calloc(tab->width + 1, sizeof(char))))
		return (-1);
	c = ' ';
	if (tab->zero)
		c = '0';
	if (tab->left)
	{
		ft_memset(tab->toprint, ' ', tab->width);
		ft_memmove(tab->toprint, str, ft_strlen(str));
	}
	else
	{
		ft_memset(tab->toprint, c, tab->width);
		i = ft_strlen(str);
		while (i)
			tab->toprint[--tab->width] = str[--i];
	}
	ft_putstr(tab->toprint);
	tab->res += ft_strlen(tab->toprint);
	free(str);
	return (0);
}

int		print_pointer(t_tab *tab)
{
	void	*p;
	char	*res;
	char	*str;

	p = va_arg(tab->args, void *);
	if (!(res = ft_itoa_hex((unsigned long)p, tab->convertion)))
		return (-1);
	if (tab->precision == 0)
		res[0] = '\0';
	if (tab->precision > (int)ft_strlen(res))
		fill_zero(&res, ft_strlen(res), tab->precision);
	str = ft_strjoin("0x", res);
	free(res);
	if (tab->width > ft_strlen(str))
		return (print_width(str, tab));
	else
	{
		ft_putstr(str);
		tab->res += ft_strlen(str);
		free(str);
		return (0);
	}
}
