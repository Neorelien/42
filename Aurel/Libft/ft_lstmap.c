/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:37:39 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 12:26:45 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		write_in_lst(t_list *lst, t_list *fl, void *(*f)(void *))
{
	if (!((*fl).content = (*f)((*lst).content)))
		return (1);
	if ((*lst).next)
	{
		if (!((*fl).next = malloc(sizeof(t_list) * 1)))
			return (1);
	}
	else
		fl->next = 0;
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*finallst;
	t_list	*debutlst;

	debutlst = 0;
	finallst = 0;
	while (lst)
	{
		if (!(debutlst))
		{
			if (!(finallst = malloc(sizeof(t_list) * 1)))
				return (NULL);
			debutlst = finallst;
		}
		if (write_in_lst(lst, finallst, f))
		{
			ft_lstclear(&debutlst, del);
			return (NULL);
		}
		lst = lst->next;
		finallst = finallst->next;
	}
	return (finallst);
}
