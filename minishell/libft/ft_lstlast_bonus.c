/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:10:13 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/20 17:10:26 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int size;

	size = ft_lstsize(lst);
	if (!size)
		return (lst);
	while (--size)
		lst = lst->next;
	return (lst);
}
