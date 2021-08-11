/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonuc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamual <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:55:10 by msamual           #+#    #+#             */
/*   Updated: 2020/11/01 17:05:52 by msamual          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = (*lst);
	while (tmp)
	{
		del(tmp->content);
		free(*lst);
		tmp = tmp->next;
		*lst = tmp;
	}
	*lst = NULL;
	free(tmp);
}
