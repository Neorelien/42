/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:22:18 by awery             #+#    #+#             */
/*   Updated: 2021/02/10 17:24:36 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strc(char charset, char to_find)
{
	if (charset == to_find)
		return (1);
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_nbwords(char *str, char charset, int nb_words)
{
	int i;

	i = 0;
	if (!(str[i]))
		return (0);
	if (!(ft_strc(charset, str[i])))
		nb_words++;
	i++;
	while (str[i])
	{
		if (ft_strc(charset, str[i - 1]) && !(ft_strc(charset, str[i])))
			nb_words++;
		i++;
	}
	return (nb_words);
}

void	ft_assign_tab(char **splited, char *str, char charset)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	while (*str)
	{
		len = 0;
		while (ft_strc(charset, *str))
			str++;
		if (!*str)
			return ;
		while (!ft_strc(charset, *str) && *str)
		{
			str++;
			len++;
		}
		str -= len;
		splited[i] = (char*)malloc(sizeof(char) * (len + 1));
		ft_strncpy(splited[i], str, len);
		i++;
		while (!ft_strc(charset, *str) && *str)
			str++;
	}
	splited[i] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**splited;
	int		nb_words;
	char	*str;

	str = (char *)s;
	nb_words = 0;
	nb_words = ft_nbwords(str, c, nb_words);
	printf("nb malloc = %d\n", nb_words + 1);
	if (!(splited = (char**)malloc(sizeof(char*) * (nb_words + 1))))
		return (0);
	ft_assign_tab(splited, str, c);
	splited[nb_words] = 0;
	return (splited);
}
