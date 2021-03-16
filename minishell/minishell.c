/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/16 12:27:33 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	test_struct(t_parsing *parsing);

void	get_quote(char **line, int quote)
{
	free(*line);
	if (quote == OPEN_DQUOTE)
		write(1, "dquote> ", 8);
	else
		write(1, "quote> ", 8);
	get_next_line(1, line);
}

char	*ft_str_erase_set(char *str, char quote)
{
	char	*res;
	int		o;
	int		i;

	i = 0;
	o = 0;
	//	printf("srtr = %s\n", str);
	while (str[i])
	{
		if (str[i] == quote)
			i++;
		else
		{
			i++;
			o++;
		}
	}
	//printf("o = %d\n", o);
	res = malloc(sizeof(char) * (o + 1));
	i = 0;
	o = 0;
	while (str[i])
	{
		if (str[i] == quote)
			i++;
		else
			res[o++] = str[i++];
	}
	//	printf("srtr = %s\n", str);
	res[o] = 0;
	return (res);
}

int		no_escape(char **line, int i)
{
	if (line[0][i] != 92)
		return (0);
	if (line[0][i + 1] == '$')
		return (1);
	if (line[0][i + 1] == '"')
		return (1);	
	if (line[0][i + 1] == 92)
		return (1);
	if (line[0][i + 1] == 0)
		return (1);
	return (0);
}

char	**selec_dest(t_parsing *parsing, char quote)
{
	int		i;
	char	**tmp;

	i = 0;
	if (parsing->objet == NULL)
	{
		parsing->objet = ft_strdup("");
		return (&parsing->objet);
	}
	else if (parsing->objet != NULL && parsing->data == NULL && quote > 0)
		return (&parsing->objet);
	else if (parsing->data == NULL)
	{
		parsing->data = malloc(sizeof(char*) * 2);
		parsing->data[0] = ft_strdup("");
		parsing->data[1] = NULL;
		return (&parsing->data[0]);
	}
	else if (parsing->data != NULL && quote > 0)
	{
		while (parsing->data[i])
			i++;
		return (&parsing->data[i - 1]);
	}
	while (parsing->data[i] != NULL)
		i++;
	tmp = parsing->data;
	parsing->data = malloc(sizeof(char*) * (i + 2));
	recopy_data(parsing->data, tmp);
	free(tmp);
	return (&parsing->data[i]);
}

int		get_objet(char **line, int i, t_parsing *parsing)
{
	char		**res;
	char		*tmp;
	char		to_join[2];
	static char	quote;

	res = selec_dest(parsing, quote);
	to_join[1] = 0;
	while ((line[0][i] != ' ' || (line[0][i] == ' ' && quote != 0) ) &&
			line[0][i])
	{
		if (quote != 0)
		{
			if (line[0][i] != quote)
			{
				if (quote == 34 && (line[0][i] == '$' || no_escape(line, i)))
				{
					tmp = *res;
					to_join[0] = line[0][i];
					*res = ft_strjoin_gnl(*res, to_join);
					free(tmp);
				}
				else
				{
					tmp = *res;
					to_join[0] = line[0][i];
					*res = ft_strjoin_gnl(*res, to_join);
					free(tmp);
				}
			}
			else
			{
				tmp = *res;
				to_join[0] = line[0][i];
				*res = ft_strjoin_gnl(*res, to_join);
				free(tmp);
				quote = 0;
			}
		}
		else if (is_separator_parsing(line[0], i))
		{
			if (is_separator_parsing(line[0], i) > 4)
			{
				parsing->separator[0] = '>';
				parsing->separator[1] = '>';
				parsing->separator[2] = 0;
				i = i + 2;
			}
			else
				parsing->separator[0] = line[0][i++];
			if (*res != NULL && res[0][0] == 0)
			{
				free(*res);
				*res = NULL;
			}
			break ;
		}
		else
		{
			if (line[0][i] == 34 || line[0][i] == 39)
			{
				if (i > 0 && line[0][i - 1] != 92)
					quote = line[0][i];
				if (i == 0)
					quote = line[0][i];
				tmp = *res;
				to_join[0] = line[0][i];
				*res = ft_strjoin_gnl(*res, to_join);
				free(tmp);
			}
			else
			{
				tmp = *res;
				to_join[0] = line[0][i];
				*res = ft_strjoin_gnl(*res, to_join);
				free(tmp);
			}
		}
		i++;
	}
	if (quote == 39)
		return (OPEN_SQUOTE);
	if (quote == 34)
		return (OPEN_DQUOTE);
	return (i);
}

t_parsing *new_list(t_parsing *previous_lst)
{
	t_parsing	*parsing;

	parsing = malloc(sizeof(t_parsing));
	parsing->separator[0] = 0;
	parsing->separator[1] = 0;
	parsing->separator[2] = 0;
	parsing->next = NULL;
	parsing->objet = NULL;
	parsing->data = NULL;
	if (previous_lst != NULL)
		previous_lst->next = parsing;
	return (parsing);
}

char	**recopy_data(char **data, char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		data[i] = temp[i];
		i++;
	}
	data[i] = NULL;
	return (data);
}

int		recursive_parsing(char **line, t_parsing *parsing, int i)
{
	while (line[0][i] == ' ')
		i++;
	if (!line[0][i])
		return (i);
	i = get_objet(line, i, parsing);
	if (parsing->separator[0] != 0)
		i = recursive_parsing(line, new_list(parsing), i);
	else if (line[0][i])
		i = recursive_parsing(line, parsing, i);
	return (i);
}

void	test_struct(t_parsing *parsing)
{
	int i;

	i= 0;
	if (parsing->objet != NULL)
		printf("objet =%s|\n", parsing->objet);
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		printf("data %d =%s|\n", i, parsing->data[i]);
		i++;
	}
	if (parsing->separator[0] != 0)
		printf("sep = %s\n", parsing->separator);
	if (parsing->next != NULL)
		test_struct(parsing->next);
}

int		clean_parsing(t_parsing *parsing)
{
	int i;
	int ex;

	i= 0;
	ex = 0;
	if (parsing->objet != NULL)
	{
		if (ft_strncmp(parsing->objet, "exit", 5) == 0)
			ex = 1;
		free(parsing->objet);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		free(parsing->data[i]);
		i++;
	}
	if (parsing->data != NULL)
		free(parsing->data);
	if (parsing->next != NULL)
		ex = clean_parsing(parsing->next);
	free(parsing);
	return (ex);
}

void	get_open_quote(int *i, char **line, t_parsing *parsing)
{
	char *tmp;

	get_quote(line, *i);
	tmp = *line;
	*line = ft_strjoin("\n", *line);
	*i = 0;
	free(tmp);
	*i = recursive_parsing(line, ft_lstlast(parsing), *i);
}

void	data_formatation(t_parsing *parsing, char ***env)
{
	int	i;
}

void	fonction_router(t_parsing *parsing, char ***env, t_utils *utils)
{
	//	data_formatation(parsing, env);
	test_struct(parsing);
	if (ft_sep(*parsing) <= 0)
		;
	//	else if (ft_strncmp(parsing->objet, "echo", 4) == 0)
	//		echo(*parsing, env, utils);	
	else if (ft_strncmp(parsing->objet, "cd", 2) == 0)
		ft_cd(*parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "pwd", 3) == 0)
		ft_pwd(*parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "export", 6) == 0)
		ft_export(parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "env", 3) == 0)
		ft_env(parsing, *env, utils);
	else if (ft_strncmp(parsing->objet, "unset", 5) == 0)
		ft_unset(parsing, env);
	//	else if (parsing->objet != NULL)
	//		ft_other_exc(parsing, *env, utils);
	check_to_next(*parsing, env, utils);
}

void	init_utils(t_utils *utils, t_parsing *parsing)
{
	utils->pwd = NULL;
	utils->parsing_start = parsing;
	utils->cpid = -1;
}

int		main(int argc, char **argv, char **env)
{
	char			**line;
	t_parsing		*parsing;
	int				i;
	static t_utils	utils;

	parsing = new_list(NULL);
	init_utils(&utils, parsing);
	argc = 0;
	argv = NULL;
	utils.tmp = malloc(sizeof(char*) * (ft_doubletab_len(env) + 1));
	recopy_data(utils.tmp, env);
	env = utils.tmp;
	i = 0;
	line = malloc(sizeof(char*) * 1);
	while (ft_display_rep(env, utils) && write(1, "-> ", 3) && get_next_line(1, line))
	{
		i = recursive_parsing(line, parsing, i);
		while (i == OPEN_SQUOTE || i == OPEN_DQUOTE)
			get_open_quote(&i, line, parsing);
		fonction_router(parsing, &env, &utils);
		//	if (clean_parsing(utils.parsing_start))
		//		exit(1);
		//	system("leaks minishell\n");
		parsing = new_list(NULL);
		i = 0;
		free(*line);
	}
	return (0);
}
