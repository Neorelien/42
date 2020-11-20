/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:29:35 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 19:57:04 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		charinstr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int		startclean(char *str, char *pat)
{
	int	i;

	i = 0;
	while (charinstr(pat, str[i]))
		i++;
	return (i);
}

int		endclean(char *str, char *pat)
{
	int	i;
	int	len;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	while (charinstr(pat, str[len - 1]))
	{
		i++;
		len--;
	}
	return (i);
}

void	writein(char *str, char *final, int start, int end)
{
	int	i;

	i = 0;
	str += start;
	while (*(str + end))
	{
		final[i] = *str++;
		i++;
	}
	final[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*pat;
	int		start;
	int		end;
	char	*final;

	start = 0;
	while (s1[start])
		start++;
	if (!(final = (char*)malloc(sizeof(char) * start + 1)))
		return (0);
	str = (char*)s1;
	pat = (char*)set;
	start = startclean(str, pat);
	end = endclean(str, pat);
	writein(str, final, start, end);
	return (final);
}
