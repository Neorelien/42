/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:54:49 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 14:04:30 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int			ft_lstsize(t_parsing *lst)
{
	int size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_parsing	*ft_lstlast(t_parsing *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
