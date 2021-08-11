/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:49:07 by msamual           #+#    #+#             */
/*   Updated: 2020/11/10 13:25:33 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *i;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	new = NULL;
	i = lst;
	while (i)
	{
		new = ft_lstnew(f(i->content));
		if (!new)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		i = i->next;
	}
	return (res);
}
