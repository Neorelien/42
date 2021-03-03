/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:14:09 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 17:14:11 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		tmp = temp;
		temp = temp->next;
		ft_lstdelone(tmp, del);
	}
	*lst = NULL;
}
