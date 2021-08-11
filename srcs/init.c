/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:31:41 by msamual           #+#    #+#             */
/*   Updated: 2020/11/12 15:06:41 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	clear(t_tab *tab)
{
	tab->toprint = NULL;
	tab->convertion = -1;
	tab->width = 0;
	tab->zero = 0;
	tab->left = 0;
	tab->precision = -1;
}
