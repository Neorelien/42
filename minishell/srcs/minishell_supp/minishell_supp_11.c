/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_11.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:19:25 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 14:20:33 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void	virpoin_error(char *line, int i)
{
	if (line[i] == ' ')
		;
	if (!line[i])
		printf("minishell: parse error near ';'\n");
	else if (is_separator_parsing(line, i))
	{
		if (line[i] == ';')
			printf("minishell: parse error near ';;'\n");
		else
			printf("minishell: parse error near ';'\n");
		exit(130);
	}
}

void	pipe_error(char *line, int i, t_parsing *parsing)
{
	int o;

	o = i;
	if (parsing->objet != NULL)
		return ;
	while (line[o] == ' ' && line[o])
		o++;
	if (!line[o])
		printf("minishell: parse error near '|'\n");
	if (is_separator_parsing(line, o))
	{
		if (line[o] == '|')
			printf("minishell: parse error near '||'\n");
		else
			printf("minishell: parse error near '|'\n");
		exit(130);
	}
}

void	redir_error(char *line, int i)
{
	int o;

	o = i;
	while (line[o] == ' ' && line[o])
		o++;
	if (!line[o])
	{
		printf("minishell: parse error near 'newline'\n");
		exit(130);
	}
	if (is_separator_parsing(line, o) > 4)
	{
		printf("minishell: parse error near '%c%c'\n", line[o], line[o + 1]);
		exit(130);
	}
	else if (is_separator_parsing(line, o))
	{
		printf("minishell: parse error near '%c'\n", line[o]);
		exit(130);
	}
}

void	check_pars_error(char *line, int i, t_parsing *parsing, int p)
{
	if (line[p] == ';')
		virpoin_error(line, i);
	if (line[p] == '|')
		pipe_error(line, i, parsing);
	if (line[p] == '>')
		redir_error(line, i);
}
