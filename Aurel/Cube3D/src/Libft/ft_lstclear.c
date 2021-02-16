/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:37:27 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 14:56:37 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *suiv;
	t_list *temp;

	if (*lst)
		suiv = *lst;
	else
		return ;
	while (suiv)
	{
		temp = suiv;
		suiv = (*suiv).next;
		ft_lstdelone(temp, del);
	}
	free(suiv);
	*lst = 0;
}
