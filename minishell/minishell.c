/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/08 14:00:58 by awery            ###   ########.fr       */
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

int		get_objet(char **line, int i, char **dest)
{
	char	*res;
	char	*tmp;
	char	to_join[2];
	char	quote;

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	quote = -1;
	while ((line[0][i] != ' ' || (line[0][i] == ' ' && quote != -1) ) && line[0][i])
	{
		tmp = res;
		to_join[0] = line[0][i];
		res = ft_strjoin_gnl(res, to_join);
		free(tmp);
		if ((line[0][i] == 39 || line[0][i] == 34 ) && quote == -1)
			quote = line[0][i];
		else if (line[0][i] == quote)
		{
			tmp = res;
		//	printf("res ava= %s\n", res);
			res = ft_str_erase_set(res, quote);
		//	printf("res apr= %s\n", res);
			free(tmp);
			quote = -1;
		}
		i++;
	}
	*dest = res;
	if (quote == 39)
	{
		tmp = *dest;
		*dest = ft_str_erase_set(res, 39);
		free(tmp);
		return (OPEN_SQUOTE);
	}
	if (quote == 34)
	{
		tmp = *dest;
		*dest = ft_str_erase_set(res, 34);
		free(tmp);
		return (OPEN_DQUOTE);
	}
	return (i);
}
/*
int		get_next_string(int i, char *line, char **dest, char quote)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	if (quote == ' ')
	{
		free(res);
		return (whithout_quote(i, line, dest));
	}
	else
		while (line[i] != quote)
		{
			if (!line[i])
			{
				*dest = res;
				if (quote == 39)
					return (OPEN_SQUOTE);
				else
					return (OPEN_DQUOTE);
			}
			tmp = res;
			to_join[0] = line[i];
			res = ft_strjoin_gnl(res, to_join);
			free(tmp);
			i++;
		}
	*dest = res;
	i++;//le prochain caractere qui sera lu est celui juste apres le quote
	return (i);
}

int		get_objet(char **line, int i, char **dest)
{
	int		quote[2];

	if ((quote[0] = 0) == 0 && line[0][i] == 39)
		quote[0] = 1;
	if ((quote[1] = 0) == 0 && line[0][i] == 34)
		quote[1] = 1;
if (quote[0] == 1 || quote[1] == 1)
		i++;
	if (quote[0])
		return (get_next_string(i, *line, dest, ' '));
	else if (quote[1])
		return (get_next_string(i, *line, dest, ' '));
	else
		return (get_next_string(i, *line, dest, ' '));
	return (0);
}
*/
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

void	recopy_data(char **data, char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		data[i] = temp[i];
		i++;
	}
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
		*i = get_objet(line, *i, &parsing->data[0]);
		if (is_separator(parsing->data[0]))
		{
			parsing->separator[0] = parsing->data[0][0];
			parsing->separator[1] = parsing->data[0][1];
			parsing->data[0] = NULL;
			return (*i);
		}
		return (*i);
		//	printf("1 on va ici et data[0] =%s| data[1]=%s\n", parsing->data[0], parsing->data[1]);
	}
	else
	{
		//	printf("2 on va ici et data[0] =%s| data[1]=%s\n", parsing->data[0], parsing->data[1]);
		while (parsing->data[o] != NULL)
			o++;
		//	printf("o = %d\n", o);
		temp = parsing->data;
		parsing->data = malloc(sizeof(char*) * (o + 2));
		recopy_data(parsing->data, temp);
		free(temp);
		*i = get_objet(line, *i, &parsing->data[o]);
		if (is_separator(parsing->data[o]))
		{
			parsing->separator[0] = parsing->data[o][0];
			parsing->separator[1] = parsing->data[o][1];
			parsing->data[o] = NULL;
			return (*i);
		}
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
		i = get_objet(line, i, &parsing->objet);
		//	printf("1 on va ici et objet = %s\n", parsing->objet);
		if (is_separator(parsing->objet))
		{
			parsing->separator[0] = parsing->objet[0];
			parsing->separator[1] = parsing->objet[1];
			recursive_parsing(line, new_list(parsing), i);
		}
		else if (line[0][i])
			i = recursive_parsing(line, parsing, i);
		else
			return (i);
		return (i);
	}
	else
	{
	//	printf(" objet = %s\n", parsing->objet);
		i = get_data(&i, parsing, line);
		if 	(parsing->separator[0] != 0)
		{
		//	printf("onvalaaaaa, line = %s,  i = %d\n", *line, i);
			recursive_parsing(line, new_list(parsing), i);
		}
		else if (line[0][i])
		{
		//	printf("onvaiciiiiiiii\n");
			i = recursive_parsing(line, parsing, i);
		}
		else
		{
	//	printf("on va ici2\n");
			return (i);
		}
		return (i);
	}
}

void	test_struct(t_parsing *parsing)
{
	int i;

	i= 0;
	if (parsing->objet != NULL)
		printf("objet =%s|\n", parsing->objet);
	//	printf("on va la 2\n");
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		printf("data %d =%s|\n", i, parsing->data[i]);
		i++;
	}
	//	printf("on va la 3\n");
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
	//	printf("on va la 2\n");
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

void	fonction_router(t_parsing *parsing, char ***env, t_utils *router)
{
	if (ft_strncmp(parsing->objet, "echo", 4) == 0)
		echo(*parsing);	
	else if (ft_strncmp(parsing->objet, "cd", 2) == 0)
		ft_cd(*parsing, env, router);
	else if (ft_strncmp(parsing->objet, "pwd", 3) == 0)
		ft_pwd(*parsing, *env, *router);
	else if (ft_strncmp(parsing->objet, "export", 6) == 0)
		ft_export(parsing, env);
	else if (ft_strncmp(parsing->objet, "env", 3) == 0)
		ft_env(parsing, env);
	else if (ft_strncmp(parsing->objet, "unset", 5) == 0)
		ft_unset(parsing, env);
//	else
//		ft_other_exc(parsing);
}

void	init_utils(t_utils *router)
{
	router->pwd = NULL;
	router->env_alrdy_mall = 0;
}

int		main(int argc,char **argv, char **env)
{
	char			**line;
	t_parsing		*parsing;
	int				i;
	char			***p_env;
	static t_utils router;

	init_utils(&router);
	p_env = malloc(sizeof(char**));
	*p_env = env;
	argc = 0;
	argv = NULL;
	parsing = new_list(NULL);
	i = 0;
	line = malloc(sizeof(char*) * 1);
	while (ft_display_rep(env, router) && write(1, "-> ", 3) && get_next_line(1, line))
	{
		i = recursive_parsing(line, parsing, i);
		while (i == OPEN_SQUOTE || i == OPEN_DQUOTE)
			get_open_quote(&i, line, parsing);
		fonction_router(parsing, p_env, &router);
		if (clean_parsing(parsing))
			exit(1);
		//	system("leaks minishell\n");
		parsing = new_list(NULL);
		i = 0;
		free(*line);
	}
	return (0);
}
