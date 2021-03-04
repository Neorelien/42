/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/04 11:14:02 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	test_struct(t_parsing *parsing);

int		whithout_quote(int i, char *line, char **dest)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	while (line[i] != ' ' && line[i])
	{
		tmp = res;
		to_join[0] = line[i];
		res = ft_strjoin_gnl(res, to_join);
		free(tmp);
		i++;
	}
	*dest = res;
	return (i);
}

int		get_next_string(int i, char *line, char **dest, char quote)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	if (quote == ' ')
		return (whithout_quote(i, line, dest));
	else
		while (line[i] != quote)
		{
			if (!line[i])
				return (OPEN_QUOTE);
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

int		get_objet(char *line, int i, char **dest)
{
	int		quote[2];

	if ((quote[0] = 0) == 0 && line[i] == 39)
		quote[0] = 1;
	if ((quote[1] = 0) == 0 && line[i] == 34)
		quote[1] = 1;
	if (quote[0] == 1 || quote[1] == 1)
		i++;
	if (quote[0])
		return (get_next_string(i, line, dest, 39));
	else if (quote[1])
		return (get_next_string(i, line, dest, 34));
	else
		return (get_next_string(i, line, dest, ' '));
	return (0);
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
	parsing->option = NULL;
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

void	get_option(t_parsing *parsing, char *option)
{
	int		o;
	char	**temp;
	char	*tmp;

	o = 0;
	tmp = option;
	option = ft_strdup(&option[1]);
	free(tmp);
	if (parsing->option == NULL)
	{
		parsing->option = malloc(sizeof(char*) * 2);
		parsing->option[1] = NULL;
		parsing->option[0] = option;
	}
	else
	{
		while (parsing->option[o] != NULL)
			o++;
		temp = parsing->option;
		parsing->option = malloc(sizeof(char*) * (o + 1));
		recopy_data(parsing->option, temp);
		free(temp);
		parsing->option[o + 1] = NULL;
	}

}

void	get_data(int *i, t_parsing *parsing, char **line)
{
	char	**temp;
	int		o;

	o = 0;
	if (parsing->data == NULL)
	{
		parsing->data = malloc(sizeof(char*) * 2);
		parsing->data[1] = NULL;
		*i = get_objet(*line, *i, &parsing->data[0]);
		if (parsing->data[o][0] == '-')
		{
			get_option(parsing, parsing->data[o]);
	//		printf("o = %d\n", o);
			parsing->data[0] = NULL;
		}
		printf("1 on va ici et data[0] =%s| data[1]=%s\n", parsing->data[0], parsing->data[1]);
	}
	else
	{
		while (parsing->data[o] != NULL)
			o++;
		temp = parsing->data;
		parsing->data = malloc(sizeof(char*) * (o + 1));
		recopy_data(parsing->data, temp);
		free(temp);
		*i = get_objet(*line, *i, &parsing->data[o]);
		if (parsing->data[o][0] == '-')
		{
			get_option(parsing, parsing->data[o]);
	//		printf("o = %d\n", o);
			parsing->data[o] = NULL;
		}
		parsing->data[o + 1] = NULL;
	}
}

void	recursive_parsing(char **line, t_parsing *parsing, int i)
{
	while (line[0][i] == ' ')
		i++;
	if (!line[0][i])
		return ;
	if (parsing->objet == NULL)
	{
		i = get_objet(*line, i, &parsing->objet);
	//	printf("1 on va ici et objet = %s\n", parsing->objet);
		if (is_separator(parsing->objet))
		{
			parsing->separator[0] = parsing->objet[0];
			parsing->separator[1] = parsing->objet[1];
			recursive_parsing(line, new_list(parsing), i);
		}
		else if (line[0][i])
			recursive_parsing(line, parsing, i);
		else
			return ;
	}
	else
	{
	//	printf("2 on va ici et objet = %s\n", parsing->objet);
		get_data(&i, parsing, line);
		if (line[0][i])
			recursive_parsing(line, parsing, i);
		else
			return ;
	}
}

void	test_struct(t_parsing *parsing)
{
	int i;

	i= 0;
	if (parsing->objet != NULL)
		printf("objet =%s|\n", parsing->objet);
	while (parsing->option[i] != NULL)
	{
		printf("option %d =%s|\n", i, parsing->option[i]);
		i++;
	}
	i = 0;
	while (parsing->data[i] != NULL)
	{
		printf("data %d =%s|\n", i, parsing->data[i]);
		i++;
	}
	//printf("on va la 2\n");
	if (parsing->next != NULL)
		test_struct(parsing->next);
}

int		main(void)
{
	char		**line;
	t_parsing	*parsing;
	t_parsing	*start;
	int			i;

	parsing = new_list(NULL);
	start = parsing;
	i = 0;
	line = malloc(sizeof(char*) * 1);
	while (write(1, "-> ", 3) && get_next_line(1, line))
	{
		recursive_parsing(line, parsing, i);
		test_struct(parsing);
		i = 0;
		free(*line);
	}
	return (0);
}