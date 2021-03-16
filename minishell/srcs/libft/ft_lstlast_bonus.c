/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:10:13 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/16 12:00:01 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_parsing	*ft_lstlast(t_parsing *lst)
{
	int size;

	size = ft_lstsize(lst);
	if (!size)
		return (lst);
	while (--size)
		lst = lst->next;
	return (lst);
}
