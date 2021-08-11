/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:45:19 by msamual           #+#    #+#             */
/*   Updated: 2020/11/10 22:03:14 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(unsigned int n)
{
	int				res;

	res = 0;
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res + 1);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char			*res;
	int				len;

	len = intlen(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (n > 9)
	{
		res[--len] = n % 10 + 48;
		n /= 10;
	}
	res[len - 1] = n + 48;
	return (res);
}
