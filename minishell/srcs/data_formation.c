/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:36:09 by aurelien          #+#    #+#             */
/*   Updated: 2021/03/17 11:16:56 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

void	quote_status(t_parsing *parsing, int *quote, int i, char *new_obj)
{
	if (*quote == 0 && parsing->objet[i] == 34)
	{
		if (i == 0)
		{
			ft_cpy(&new_obj, parsing->objet[i]);
			*quote = parsing->objet[i];
		}
		if (i > 0 && parsing->objet[i - 1] != 92)
		{
			ft_cpy(&new_obj, parsing->objet[i]);
			*quote = parsing->objet[i];
		}
		else
			ft_cpy(&new_obj, parsing->objet[i]);
	}
	else if (*quote == 0 && parsing->objet[i] == 39)
	{
		ft_cpy(&new_obj, parsing->objet[i]);
		*quote = parsing->objet[i];
	}
	else if (parsing->objet[i] == *quote)
	{
		if (i > 0 && parsing->objet[i - 1] != 92 && *quote == 34)
			ft_cpy(&new_obj, parsing->objet[i]);
		else
		{
			ft_cpy(&new_obj, parsing->objet[i]);
			*quote = 0;
		}
	}
	else
		ft_cpy(&new_obj, parsing->objet[i]);
}

int		look_for_env(t_parsing *parsing, int quote, int i, char *new_obj, char ***env)
{
	char	*env_name;
	char	*env_cont;
	int		o;

	o = 0;
	env_name = ft_strdup("");
	if (i > 0 && parsing->objet[i - 1] == 92)
		ft_cpy(&new_obj, parsing->objet[i++]);
	else if (quote == 39)
		ft_cpy(&new_obj, parsing->objet[i++]);
	else if (quote == 0 && parsing->objet[i + 1] == 39)
		i++;
	else if (!ft_isalnum(parsing->objet[i + 1]))
		ft_cpy(&new_obj, parsing->objet[i++]);
	else
	{
		while (ft_isalnum(parsing->objet[i]))
			ft_cpy(&env_name, parsing->objet[i++]);
		env_cont = find_in_env(*env, env_name);
		if (env_cont == NULL)
			;
		else
			while (env_cont[o])
				ft_cpy(&new_obj, env_cont[o++]);
		free(env_name);
	}
	return (i);
}

void	trans_env(t_parsing *parsing, char ***env)
{
	int		i;
	int		quote;
	char	*new_obj;

	new_obj = ft_strdup("");
	quote = 0;
	i = 0;
	while (parsing->objet[i])
	{
		if (parsing->objet[i] == 34 || parsing->objet[i] == 39)
		{
			ft_cpy(&new_obj, parsing->objet[i]);
			quote_status(parsing, &quote, i, new_obj);
			i++;
		}
		if (parsing->objet[i] == '$')
			i = look_for_env(parsing, quote, i, new_obj, env);
		else
			i++;
	}
	free(parsing->objet);
	parsing->objet = new_obj;
}

void	form_objet(t_parsing *parsing, char ***env)
{
	trans_env(parsing, env);
}

void	data_formation(t_parsing *parsing, char ***env)
{
	if (parsing->objet != NULL)
		form_objet(parsing, env);
}
