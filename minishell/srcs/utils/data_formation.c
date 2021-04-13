/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:09 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 14:02:55 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

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
	else if (!ft_isalnum(objet[0][utils->i + 1])
			&& objet[0][utils->i + 1] != '_')
		look_for_env_supp_1(objet, &utils->new_obj, utils, &tls);
	else
		look_for_env_supp_2(objet, env, utils, &tls);
	free(tls.env_name);
	return (utils->i);
}

void	trans_bs_quote(char **objet, int token)
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
((quote_status(objet, &quote, i) && ft_cpy(&new_obj, objet[0][i])) || 1))
			i++;
		else if (objet[0][i] == 92)
		{
			if (token)
				i = look_for_bs_token(objet, i, &new_obj);
			else
				i = look_for_bs(objet, quote, i, &new_obj);
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
		trans_bs_quote(&parsing->objet, 0);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		trans_env(&parsing->data[i], env, utils);
		if (!ft_strncmp(parsing->objet, "echo", 5))
		{
			trans_bs_quote(&parsing->data[i], 0);
			trans_bs_quote(&parsing->data[i], 1);
		}
		else
			trans_bs_quote(&parsing->data[i], 0);
		i++;
	}
}
