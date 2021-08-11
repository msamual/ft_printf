/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:39:11 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:27:27 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		fill_zero(char **str, int len, int prec)
{
	char	*res;
	int		neg;
	int		size;

	neg = 0;
	if ((*str)[0] == '-')
		neg = 1;
	size = prec + neg;
	res = (char *)ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (-1);
	ft_memset(res, '0', prec + neg);
	while (len)
		res[--size] = (*str)[--len];
	if (neg)
	{
		res[0] = '-';
		res[size] = '0';
	}
	free(*str);
	*str = res;
	return (0);
}

void	minus_na_mesto(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && i && str[i - 1] == '0')
		{
			str[i] = '0';
			str[0] = '-';
		}
	}
}

int		print_width_dec(char *str, t_tab *tab)
{
	int		i;
	char	c;

	if (!(tab->toprint = ft_calloc(tab->width + 1, sizeof(char))))
		return (-1);
	c = ' ';
	if (tab->zero && tab->precision < 0)
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
	minus_na_mesto(tab->toprint);
	ft_putstr(tab->toprint);
	tab->res += ft_strlen(tab->toprint);
	return (0);
}

int		print_decimal(t_tab *tab)
{
	int				nb;
	unsigned int	len;
	char			*str;

	nb = va_arg(tab->args, int);
	str = ft_itoa(nb);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (tab->precision == 0 && nb == 0)
		str[0] = '\0';
	if (tab->precision >= (int)len)
		if (fill_zero(&str, len, tab->precision) == -1)
			return (-1);
	len = ft_strlen(str);
	if (tab->width > len)
		return (print_width_dec(str, tab));
	else
	{
		ft_putstr(str);
		tab->res += len;
		free(str);
		return (0);
	}
	return (0);
}
