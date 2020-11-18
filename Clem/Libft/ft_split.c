/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 17:17:54 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/18 14:14:09 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strc(char *charset, char to_find)
{
	unsigned int	j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == to_find)
			return (1);
		j++;
	}
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

void	ft_nbwords(char *str, char *charset, int *nb_words)
{
	int i;

	i = 0;
	if (!(ft_strc(charset, str[i])))
		nb_words[0]++;
	i++;
	while (str[i])
	{
		if (ft_strc(charset, str[i - 1]) && !(ft_strc(charset, str[i])))
			nb_words[0]++;
		i++;
	}
}

void	ft_assign_tab(char **splited, char *str, char *charset)
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
		splited[i] = (char*)malloc(sizeof(char) * len);
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
	ft_nbwords(str, &c, &nb_words);
	splited = (char**)malloc(sizeof(char*) * nb_words + 1);
	ft_assign_tab(splited, str, &c);
	splited[nb_words] = 0;
	return (splited);
}
