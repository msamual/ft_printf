/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:01:42 by msamual           #+#    #+#             */
/*   Updated: 2020/11/13 16:32:41 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef	struct		s_tab
{
	va_list			args;
	char			*format;
	char			*toprint;
	int				res;
	int				i;

	int				convertion;
	unsigned int	width;
	int				zero;
	int				left;
	int				precision;
}					t_tab;

int					ft_printf(const char *format, ...);
int					execute(t_tab *tab);
void				parse(t_tab *tab);
void				putstr_width(char *str, int width);
int					print_string(t_tab *tab);
int					print_pointer(t_tab *tab);
int					print_percent(t_tab *tab);
void				print_hex(void *p, char c, char *res, int pos);
int					print_width(char *str, t_tab *tab);
int					print_width_un(char *str, t_tab *tab);
int					print_decimal(t_tab *tab);
int					print_unsigned(t_tab *tab);
void				clear(t_tab *tab);
int					fill_zero(char **str, int len, int prec);
char				*ft_itoa_unsigned(unsigned int n);
char				*ft_itoa_hex(unsigned long n, int con);
int					print_hexadecimal(t_tab *tab);

#endif
