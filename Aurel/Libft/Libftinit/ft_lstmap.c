/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:37:39 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 14:57:41 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*r_list;
	t_list	*r_point;

	if (!lst || !f)
		return (NULL);
	r_list = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		r_point = ft_lstnew(f(lst->content));
		if (!(r_point))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&r_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&r_list, r_point);
	}
	return (r_list);
}
