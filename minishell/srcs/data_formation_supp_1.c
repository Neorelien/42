/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formation_supp_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:47:27 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 18:15:00 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		look_for_bs_token(char **objet, int i, char **new_obj)
{
	if (is_token_remplace(objet[0][i + 1], new_obj))
	{
		if (objet[0][i + 1] != 0)
			i = i + 2;
		else
			i++;
	}
	else
	{
		if (objet[0][i + 1] != 0 && objet[0][i + 1] == 92)
		{
			ft_cpy(new_obj, objet[0][i + 1]);
			i = i + 2;
		}
		else
		{
			ft_cpy(new_obj, objet[0][i]);
			i++;
		}
	}
	return (i);
}

void	trans_env(char **objet, char ***env, t_utils *utils)
{
	utils->new_obj = ft_strdup("");
	utils->quote = 0;
	utils->i = 0;
	while (objet[0][utils->i])
	{
		if (objet[0][utils->i] == 34 || objet[0][utils->i] == 39)
		{
			quote_status(objet, &utils->quote, utils->i);
			ft_cpy(&utils->new_obj, objet[0][utils->i++]);
		}
		else if (objet[0][utils->i] == '$')
			utils->i = look_for_env(objet, env, utils);
		else
			ft_cpy(&utils->new_obj, objet[0][utils->i++]);
	}
	free(objet[0]);
	objet[0] = utils->new_obj;
}

int		is_token_remplace(char c, char **objet)
{
	if (c == 'a')
		ft_cpy(objet, 7);
	else if (c == 'b')
		ft_cpy(objet, 8);
	else if (c == 't')
		ft_cpy(objet, 9);
	else if (c == 'n')
		ft_cpy(objet, 10);
	else if (c == 'v')
		ft_cpy(objet, 11);
	else if (c == 'f')
		ft_cpy(objet, 12);
	else if (c == 'r')
		ft_cpy(objet, 13);
	else
		return (0);
	return (1);
}

int		look_for_bs(char **objet, int quote, int i, char **new_obj)
{
	if (quote)
	{
		if ((objet[0][i + 1] == 92 || objet[0][i + 1] == 34) && quote == 34)
		{
			ft_cpy(new_obj, objet[0][i + 1]);
			if (objet[0][i + 1] != 0)
				i = i + 2;
			else
				i++;
		}
		else
			ft_cpy(new_obj, objet[0][i++]);
	}
	else
	{
		if (objet[0][i] == 92)
		{
			ft_cpy(new_obj, objet[0][i + 1]);
			if (objet[0][i + 1] != 0)
				i = i + 2;
			else
				i++;
		}
	}
	return (i);
}

int		quote_status(char **objet, int *quote, int i)
{
	if (*quote == 0 && objet[0][i] == 34)
		*quote = objet[0][i];
	else if (*quote == 0 && objet[0][i] == 39)
		*quote = objet[0][i];
	else if (objet[0][i] == *quote)
		*quote = 0;
	return (0);
}
