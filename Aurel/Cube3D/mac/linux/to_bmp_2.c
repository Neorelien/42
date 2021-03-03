/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bmp_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:59:52 by awery             #+#    #+#             */
/*   Updated: 2021/02/13 17:36:49 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

char			*add_to_char(char *str1, char c)
{
	char	*res;
	int		lenght;
	int		i;

	i = 0;
	lenght = 0;
	lenght += ft_strlen(str1);
	res = malloc(sizeof(char) * (lenght + 2));
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	return (res);
}

char			*ft_rev_char(char *str)
{
	char	*res;
	int		i;
	int		len;
	int		o;

	o = -1;
	i = 0;
	len = ft_strlen(str);
	res = malloc(sizeof(char) * len + 1);
	while (++o < len)
	{
		if (i == 0)
		{
			if (o == len - 1)
				res[o] = str[len - 1 - o];
			else
				res[o + 1] = str[len - 1 - o];
			i++;
		}
		else if ((i = 0) == 0)
			res[o - 1] = str[len - 1 - o];
	}
	res[len] = '\0';
	return (res);
}

static void		supp_2(char *bmp, int *i, char *res)
{
	char *tmp;

	tmp = ft_convert_base(res, "0123456789abcdef", "0123456789");
	i[2] = ft_atoi(tmp);
	bmp[i[1]++] = i[2];
	free(tmp);
}

void			ft_cp_in_bmp(char *bmp, char *file_size, char *tmp,
		char *maltemp)
{
	char	*res;
	int		i[3];

	i[1] = 0;
	i[0] = 0;
	res = ft_strdup("");
	file_size = ft_rev_char(file_size);
	maltemp = file_size;
	while (file_size[i[0]])
	{
		tmp = res;
		res = add_to_char(res, file_size[i[0]++]);
		free(tmp);
		if (i[0] == 2 || file_size[i[0]] == '\0')
		{
			supp_2(bmp, i, res);
			file_size = &file_size[i[0]];
			free(res);
			res = ft_strdup("");
			i[0] = 0;
		}
	}
	free(maltemp);
	free(res);
}
