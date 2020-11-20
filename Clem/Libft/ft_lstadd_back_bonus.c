/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:07:21 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 17:07:25 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	if (!lst)
	{
		*alst = new;
		new->next = NULL;
		return ;
	}
	if (!new)
		return ;
	lst = ft_lstlast(lst);
	lst->next = new;
	new->next = NULL;
}
