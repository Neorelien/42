/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:25:46 by awery             #+#    #+#             */
/*   Updated: 2021/01/15 01:06:44 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		i;
	char	*src;

	src = (char*)s1;
	i = 0;
	if (!(cpy = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
