/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/15 16:22:25 by awery            ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/03/15 14:10:51 by cmoyal           ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2021/03/15 13:46:14 by awery            ###   ########.fr       */
=======
/*   Updated: 2021/03/15 13:44:57 by cmoyal           ###   ########.fr       */
>>>>>>> 9f7d204f5d192a9d581c55a0d3799a820053cbf3
>>>>>>> 96967b6163934118bf355085b824ecfab0d774aa
>>>>>>> f5fe3581fd41da4265cdccc14362bb862b2d987e
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	test_struct(t_parsing *parsing);

void	get_dquote(char **line)
{
	free(*line);
	write(1, "dquote> ", 8);
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

int		get_objet(char **line, int i, char **dest, t_parsing *parsing)
{
	char	*res;
	char	*tmp;
	char	to_join[2];
	char	quote;

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	quote = -1;
	while ((line[0][i] != ' ' || (line[0][i] == ' ' && quote != -1) ) &&
			line[0][i])
	{
		if (quote != -1)
		{
			if (line[0][i] != quote)
			{
				if (quote == 34 && (line[0][i] == '$' || no_escape(line, i)))
				{
					tmp = res;
					to_join[0] = line[0][i];
					res = ft_strjoin_gnl(res, to_join);
					free(tmp);
				}
				else
				{
					tmp = res;
					to_join[0] = 92;
					res = ft_strjoin_gnl(res, to_join);
					free(tmp);
					tmp = res;
					to_join[0] = line[0][i];
					res = ft_strjoin_gnl(res, to_join);
					free(tmp);
				}
			}
			else
				quote = -1;
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
			free(res);
			res = NULL;
			break ;
		}
		else
		{
			if (line[0][i] == 34 || line[0][i] == 39)
			{
				if (i > 0 && line[0][i - 1] != 92)
					quote = line[0][i];
			}
			else
			{
				tmp = res;
				to_join[0] = line[0][i];
				res = ft_strjoin_gnl(res, to_join);
				free(tmp);
			}
		}
		i++;
	}
	*dest = res;
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

int		get_data(int *i, t_parsing *parsing, char **line)
{
	char	**temp;
	int		o;

	o = 0;
	if (parsing->data == NULL || parsing->data[0] == NULL)
	{
		parsing->data = malloc(sizeof(char*) * 2);
		parsing->data[1] = NULL;
		*i = get_objet(line, *i, &parsing->data[0], parsing);
		return (*i);
	}
	else
	{
		while (parsing->data[o] != NULL)
			o++;
		temp = parsing->data;
		parsing->data = malloc(sizeof(char*) * (o + 2));
		recopy_data(parsing->data, temp);
		free(temp);
		*i = get_objet(line, *i, &parsing->data[o], parsing);
		parsing->data[o + 1] = NULL;
		return (*i);
	}
}

int		recursive_parsing(char **line, t_parsing *parsing, int i)
{
	while (line[0][i] == ' ')
		i++;
	if (!line[0][i])
		return (i);
	if (parsing->objet == NULL)
	{
		i = get_objet(line, i, &parsing->objet, parsing);
		if (parsing->separator[0] != 0)
			recursive_parsing(line, new_list(parsing), i);
		else if (line[0][i])
			i = recursive_parsing(line, parsing, i);
		else
			return (i);
		return (i);
	}
	else
	{
		i = get_data(&i, parsing, line);
		if (parsing->separator[0] != 0)
			recursive_parsing(line, new_list(parsing), i);
		else if (line[0][i])
			i = recursive_parsing(line, parsing, i);
		else
			return (i);
		return (i);
	}
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

	get_dquote(line);
	tmp = *line;
	if (*i == OPEN_SQUOTE)
		*line = ft_strjoin("'\n", *line);
	else
		*line = ft_strjoin("\"\n", *line);
	*i = 0;
	free(tmp);
	*i = recursive_parsing(line, parsing, *i);
}

void	data_formatation(t_parsing *parsing, char ***env)
{
	int	i;
}

void	fonction_router(t_parsing *parsing, char ***env, t_utils *utils)
{
	//	data_formatation(parsing, env);
	if (ft_sep(*parsing) <= 0)
		;
	else if (ft_strncmp(parsing->objet, "echo", 4) == 0)
		echo(*parsing, env, utils);	
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
	else if (parsing->objet != NULL)
		ft_other_exc(parsing, *env, utils);
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
