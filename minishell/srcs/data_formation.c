/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:09 by aurelien          #+#    #+#             */
/*   Updated: 2021/03/22 14:16:21 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		quote_status(char **objet, int *quote, int i)
{
	if (*quote == 0 && objet[0][i] == 34)
	{
		if (i == 0)
			*quote = objet[0][i];
		else if (i > 0 && objet[0][i - 1] != 92)
			*quote = objet[0][i];
		else
			return (1);
	}
	else if (*quote == 0 && objet[0][i] == 39)
	{
		if (i > 0 && objet[0][i - 1] != 92)
			*quote = objet[0][i];
		else if (i == 0)
			*quote = objet[0][i];
		else
			return (1);
	}
	else if (objet[0][i] == *quote)
	{
		if (i > 0 && objet[0][i - 1] == 92 && *quote == 34)
			return (1);
		else
			*quote = 0;
	}
	return (0);
}

int		look_for_env(char **objet, int quote, int i, char **new_obj, char ***env)
{
	char	*env_name;
	char	*env_cont;
	int		o;

	o = 0;
	env_name = ft_strdup("");
	if (i > 0 && objet[0][i - 1] == 92)
		ft_cpy(new_obj, objet[0][i++]);
	else if (quote == 39)
		ft_cpy(new_obj, objet[0][i++]);
	else if (quote == 0 && objet[0][i + 1] == 39)
		i++;
	else if (!ft_isalnum(objet[0][i + 1]))
		ft_cpy(new_obj, objet[0][i++]);
	else
	{
		i++;
		while (ft_isalnum(objet[0][i]))
			ft_cpy(&env_name, objet[0][i++]);
		env_cont = find_in_env(*env, env_name);
		if (env_cont == NULL)
			;
		else
			while (env_cont[o])
				ft_cpy(new_obj, env_cont[o++]);
		free(env_name);
	}
	return (i);
}

void	trans_env(char **objet, char ***env)
{
	int		i;
	int		quote;
	char	*new_obj;

	new_obj = ft_strdup("");
	quote = 0;
	i = 0;
	while (objet[0][i])
	{
		if (objet[0][i] == 34 || objet[0][i] == 39)
		{
			quote_status(objet, &quote, i);
			ft_cpy(&new_obj, objet[0][i++]);
		}
		else if (objet[0][i] == '$')
			i = look_for_env(objet, quote, i, &new_obj, env);
		else
			ft_cpy(&new_obj, objet[0][i++]);
	}
	free(objet[0]);
	objet[0] = new_obj;
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
}

int		look_for_BS_token(char **objet, int quote, int i, char **new_obj)
{
	if (is_token_remplace(objet[0][i + 1], new_obj))
		i = i + 2;
	else
	{
		ft_cpy(new_obj, objet[0][i + 1]);
		i = i + 2;
	}
	return (i);
}

int		look_for_BS(char **objet, int quote, int i, char **new_obj)
{
	if (quote)
	{
		if ((objet[0][i + 1] == 92 || objet[0][i + 1] == 34) && quote == 34)
		{
			ft_cpy(new_obj, objet[0][i + 1]);
			i = i + 2;
		}
		else
			ft_cpy(new_obj, objet[0][i++]);
	}
	else
	{
		if (objet[0][i] == 92)
		{
			ft_cpy(new_obj, objet[0][i + 1]);
			i = i + 2;
		}
	}
	return (i);
}

void	trans_BS_quote(char **objet, char ***env, int token)
{
	int		i;
	int		quote;
	char	*new_obj;

	quote = 0;
	i = 0;
	new_obj = ft_strdup("");
	while (objet[0][i])
	{
		if (objet[0][i] == 34 || objet[0][i] == 39)
		{
			if (quote_status(objet, &quote, i))
				ft_cpy(&new_obj, objet[0][i]);
			i++;
		}
		else if (objet[0][i] == 92)
		{
			if (token)
				i = look_for_BS_token(objet, quote, i, &new_obj);
			else
				i = look_for_BS(objet, quote, i, &new_obj);
		}
		else
			ft_cpy(&new_obj, objet[0][i++]);
	}
	free(objet[0]);
	objet[0] = new_obj;
}

void	data_formation(t_parsing *parsing, char ***env)
{
	int	i;

	i = 0;
	if (parsing->objet != NULL)
	{
		trans_env(&parsing->objet, env);
		trans_BS_quote(&parsing->objet, env, 0);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		trans_env(&parsing->data[i], env);
		trans_BS_quote(&parsing->data[i], env, 0);
		if (!ft_strncmp(parsing->objet, "echo", 5))
			trans_BS_quote(&parsing->data[i], env, 1);
		i++;
	}
}
