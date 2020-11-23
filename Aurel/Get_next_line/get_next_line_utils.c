/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:22:18 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 16:54:58 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"

static char	*ft_strdup(const char *s1, int o)
{
	char	*cpy;
	int		i;
	char	*src;

	src = (char*)s1;
	i = 0;
	if (!(cpy = malloc(sizeof(*cpy) * ft_strlen(src))))
		return (0);
	while (src[i] && i <= o)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
