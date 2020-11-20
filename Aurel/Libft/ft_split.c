/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:22:18 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 20:16:14 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_in(char a, char charset)
{
	if (a == charset)
		return (1);
	return (0);
}

int		nb_word(char *str, char charset)
{
	int i;
	int count;
	int nbmot;

	count = 0;
	i = 0;
	nbmot = 0;
	while (str[i])
	{
		if (char_in(str[i], charset))
		{
			count = 0;
		}
		else
		{
			if (count == 0)
				nbmot++;
			count++;
		}
		i++;
	}
	return (nbmot);
}

void	split(char *str, char charset, char **tableau)
{
	int i;
	int x;
	int y;

	y = 0;
	i = 0;
	x = 0;
	while (str[i])
	{
		if (char_in(str[i], charset))
		{
			if (y > 0)
			{
				tableau[x++][y] = '\0';
			}
			y = 0;
		}
		else
			tableau[x][y++] = str[i];
		i++;
	}
	if (y > 0)
		tableau[x][y] = '\0';
}

void	count_word_lengh(char *str, char charset, char **t)
{
	int i;
	int count;
	int x;

	x = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (char_in(str[i], charset))
		{
			if (count > 0)
			{
				t[x++] = (char*)malloc((sizeof(char) * (count + 1)));
			}
			count = 0;
		}
		else
		{
			count++;
		}
		i++;
	}
	if (count > 0)
		t[x] = (char*)malloc((sizeof(char) * (count + 1)));
}

char	**ft_split(const char *s1, char charset)
{
	char	**tableau;
	int		nbmot;
	char	*str;

	str = (char*)s1;
	nbmot = 0;
	tableau = NULL;
	nbmot = nb_word(str, charset);
	if (!(tableau = (char**)malloc((sizeof(char*) * (nbmot + 1)))))
		return (0);
	count_word_lengh(str, charset, tableau);
	split(str, charset, tableau);
	tableau[nbmot] = 0;
	return (tableau);
}
