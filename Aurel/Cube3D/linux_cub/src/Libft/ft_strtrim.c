/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:29:35 by awery             #+#    #+#             */
/*   Updated: 2020/11/23 10:52:50 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				charinstr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

size_t			startclean(char *str, char *pat)
{
	size_t	i;

	i = 0;
	while (charinstr(pat, str[i]))
		i++;
	return (i);
}

size_t			endclean(char *str, char *pat)
{
	size_t	i;
	int		len;

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

static void		writein(char *str, char *final, size_t start, size_t end)
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

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	char		*pat;
	size_t		start;
	size_t		end;
	char		*final;

	if (!(s1) || !(set))
		return (0);
	start = 0;
	while (s1[start])
		start++;
	str = (char*)s1;
	pat = (char*)set;
	start = startclean(str, pat);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = endclean(str, pat);
	if (!(final = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) - start - end + 1))))
		return (0);
	writein(str, final, start, end);
	return (final);
}
