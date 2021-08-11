/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:24:16 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 15:17:11 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexlen(unsigned long n)
{
	int				res;

	res = 0;
	while (n > 15)
	{
		res++;
		n /= 16;
	}
	return (res + 1);
}

char		*ft_itoa_hex(unsigned long n, int con)
{
	char	*res;
	char	*base;
	int		len;

	if (con != 2)
		n = (unsigned int)n;
	if (con == 7)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = hexlen(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n > 15)
	{
		res[--len] = base[n % 16];
		n /= 16;
	}
	res[len - 1] = base[n];
	return (res);
}
