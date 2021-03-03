/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:07:42 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 17:08:17 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;
	t_list	*tmp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		tmp = temp;
		temp = temp->next;
		f(tmp->content);
	}
}
