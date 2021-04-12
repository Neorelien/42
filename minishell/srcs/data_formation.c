/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:09 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 16:59:22 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

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

void	look_for_env_supp_1(char **objet, char **new_obj, t_utils *utils,
		t_look *tls)
{
	if (objet[0][utils->i + 1] == '?')
	{	
		tls->ret = ft_itoa(utils->return_value);
		tls->tmp = ft_strjoin(*new_obj, tls->ret);
		free(tls->ret);
		free(*new_obj);
		*new_obj = tls->tmp;
		utils->i = utils->i + 2;	
	}
	else
		ft_cpy(new_obj, objet[0][utils->i++]);
}

void	look_for_env_supp_2(char **objet, char ***env, t_utils *utils,
		t_look *tls)
{
	utils->i++;
	while (ft_isalnum(objet[0][utils->i]) || objet[0][utils->i] == '_')
		ft_cpy(&tls->env_name, objet[0][utils->i++]);
	tls->env_cont = find_in_env(*env, tls->env_name);
	if (tls->env_cont == NULL)
		;
	else
	{
		while (tls->env_cont[tls->o])
			ft_cpy(&utils->new_obj, tls->env_cont[tls->o++]);
		free(tls->env_cont);
	}
}

int		look_for_env(char **objet, char ***env, t_utils *utils)
{
	t_look	tls;

	tls.o = 0;
	tls.env_name = ft_strdup("");
	if (utils->i > 0 && objet[0][utils->i - 1] == 92)
		ft_cpy(&utils->new_obj, objet[0][utils->i++]);
	else if (utils->quote == 39)
		ft_cpy(&utils->new_obj, objet[0][utils->i++]);
	else if (utils->quote == 0 && objet[0][utils->i + 1] == 39)
		utils->i++;
	else if (!ft_isalnum(objet[0][utils->i + 1]) && objet[0][utils->i + 1] != '_')
		look_for_env_supp_1(objet, &utils->new_obj, utils, &tls);
	else
		look_for_env_supp_2(objet, env, utils, &tls);
	free(tls.env_name);
	return (utils->i);
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

int		look_for_BS_token(char **objet, int i, char **new_obj)
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
		if (objet[0][i + 1] != 0)
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

int		look_for_BS(char **objet, int quote, int i, char **new_obj)
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

void	trans_BS_quote(char **objet, int token)
{
	int		i;
	int		quote;
	char	*new_obj;

	quote = 0;
	i = 0;
	new_obj = ft_strdup("");
	while (objet[0][i])
	{
		if ((objet[0][i] == 34 || objet[0][i] == 39) && !token &&
	quote_status(objet, &quote, i) && ft_cpy(&new_obj, objet[0][i]) && (i + 1))
				;
		else if (objet[0][i] == 92)
		{
			if (token)
				i = look_for_BS_token(objet, i, &new_obj);
			else
				i = look_for_BS(objet, quote, i, &new_obj);
		}
		else
			ft_cpy(&new_obj, objet[0][i++]);
	}
	free(objet[0]);
	objet[0] = new_obj;
}

void	data_formation(t_parsing *parsing, char ***env, t_utils *utils)
{
	int	i;

	i = 0;
	if (parsing->objet != NULL)
	{
		trans_env(&parsing->objet, env, utils);
		trans_BS_quote(&parsing->objet, 0);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		trans_env(&parsing->data[i], env, utils);
		trans_BS_quote(&parsing->data[i], 0);
		if (!ft_strncmp(parsing->objet, "echo", 5))
			trans_BS_quote(&parsing->data[i], 1);
		i++;
	}
}
