/* *****************************************:w:********************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:55:18 by awery             #+#    #+#             */
/*   Updated: 2021/03/09 16:23:41 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"
/*
t_parsing	*get_pipe(t_utils *utils)
{
	t_parsing	*parsing;
	int			i;

	i = 0;
	parsing = new_list(NULL);
	while (i < 9)
			parsing->objet[i++] = '\0';

	return (parsing);
}*/

void		cpy_double_simple(char **data, char **str)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	j = 0;
	while (data[j] != NULL)
	{
		if (p > 0)
			str[0][p++] = -2;
		i = 0;
		while (data[j][i])
			str[0][p++] = data[j][i++];
		i = 0;
		j++;
	}
	data[0][p] = 0;
}

char		*get_data_len(char **data, char **str)
{
	int		*i;
	int		o;
	char	*res;

	i = malloc(sizeof(int) * 2);
	i[0] = 0;
	i[1] = 0;
	while (data != NULL && data[i[1]] != NULL)
	{
		o = 0;
		while (data[i[1]][o] != 0)
		{
			o++;
		}
		i[0] = i[0] + o;
		i[1]++;
	}
	if (i[1] == 0)
		return (ft_strdup("0"));
	*str = malloc(sizeof(char) * (i[0] + i[1] + 1));
	cpy_double_simple(data, str);
	res = ft_itoa(i[0]);
	return (res);
}

void		send_in_pipe(int fd, t_parsing *parsing)
{
	char	*DataLen;
	char	*ObjLen;
	char	*Data;
	char	c;
	
	ObjLen = ft_itoa(ft_strlen(parsing->objet));
	DataLen = get_data_len(parsing->data, &Data);
	c = -1;
	write(fd, ObjLen, ft_strlen(ObjLen));
	write(fd, &c, 1);
	write(fd, DataLen, ft_strlen(DataLen));
	write(fd, &c, 1);
	write(fd, Data, ft_strlen(Data));
	free(ObjLen);
	free(DataLen);
	free(Data);
}

void		ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{

	(void)env;
	(void)parsing;

//	char *c;
//	int i = 0;

	if (pipe(utils->pipefd) == -1)
		printf("error pipe");
/*	utils->cpid = fork();
	if (utils->cpid == 0) // lecture du fils
	{
		close(utils->pipefd[1]);
		c = malloc(sizeof(char) * 100);
		while (i < 99)
			c[i++] = 0;
		read(utils->pipefd[0], c, 100);
		printf("c =%s|\n", c);
		close(utils->pipefd[0]);
	}
	else // lecture du pere
	{*/
		close(utils->pipefd[0]);
		send_in_pipe(utils->pipefd[1], parsing);
		close(utils->pipefd[1]);
		wait(NULL);
//	}
}
