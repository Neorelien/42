/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:20:01 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/09 02:29:53 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"
char	*ft_read_fd(t_utils *utils)
{
	int ret;
	char buff[2];
	char *result;
	char *temp;

	ret = 1;
	result = ft_strdup("");
	while (read(utils->fdout[0], buff, 1))
	{	
		buff[1] = 0;
		temp = ft_strjoin(result, buff);
		free(result);
		result = temp;
	}	
	return (result);
}

/*void	ft_redir_second(t_parsing info, char **env, t_utils *utils)
{

}*/

int	ft_reparse_count(t_parsing *info, int add)
{
	int i;
	t_parsing *parse;
	
	parse = info;
	while(parse->next != NULL && is_separator(parse->separator) > 2)
	{
		i = 0;
		parse = parse->next;
		while (parse->data != NULL && parse->data[i])
		{
			add++;
			i++;
		}
	}
	return (add + 1);
}

void ft_reparse_malloc(t_parsing *info, int add)
{
	char **doubletab;
	int i;

	i = 0;
	add = ft_reparse_count(info, add);
	doubletab = (char**)malloc(sizeof(char*) * add);
	while (info->data != NULL && info->data[i])
	{
		doubletab[i] = info->data[i];
		i++;
	}
	free(info->data);
	info->data = doubletab;	
}

void ft_reparse(t_parsing *info)
{
	int sep;
	int i;
	int add;
	t_parsing *parse;
	
	add = 0;
	while (info->data && info->data[add] != NULL)
		add++;	
	if ((sep = is_separator(info->separator)) == 0 || sep == 1 || sep == 2)
		return ;
	else if (sep == 3 || sep == 4 || sep == 5)
	{
		ft_reparse_malloc(info, add);
		parse = info;
		while(parse->next != NULL && is_separator(parse->separator) > 2)
		{
			i = 0;
			parse = parse->next;
			while (parse->data != NULL && parse->data[i])
			{
				if (info->objet == NULL)
					info->objet = ft_strdup(parse->data[i]);
				else
				{
					info->data[add] = ft_strdup(parse->data[i]);
					add++;
				}
				i++;
			}
		}
		info->data[add] = NULL;
	}
}

void	ft_redir(t_parsing info, char **env, t_utils *utils)
{
	int sep;
//	int flag_pipe;
	char *result;
	int fd;
	if (utils->fdout[0] != 0)
	{
		result = ft_read_fd(utils);
		pipe(utils->fdin);
		write(utils->fdin[1], result, ft_strlen(result));
		free(result);
		close(utils->fdout[0]);
		utils->fdout[0] = 0;
	}
	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return ;
    else if (sep == 2)
	{
		if (utils->savefd == -1)
        	ft_pipe_settings(utils);
		else 
			return ;
	}
    else if (sep == 3)                                                          
    {
		fd = open(info.next->objet, O_WRONLY | O_CREAT, 0644 | O_DIRECTORY);
            if (fd < 0)
                ft_error(strerror(errno), info.next->objet);
			if (utils->savefd == -1)
				utils->savefd = dup(utils->redir);
			dup2(fd, utils->redir);
			close(fd);                              
        ft_redir(*info.next, env, utils);                 
    }                                                                           
    else if (sep == 4)
	{
/*		if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
            ft_reroll(info, env, utils);                                        
        else                                                                    
        { */                     
            fd = open(info.next->objet, O_RDONLY);
			utils->savefdout = dup(0);
			dup2(fd, 0);
			close(fd);
  //      }
        ft_redir(*info.next, env, utils);
	}
    else if (sep == 5)                                                          
    {                                                                           
    /*    if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
            ft_reroll(info, env, utils);                                        
        else                                                                    
        {*/                      
            fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644 | O_DIRECTORY);
            if (fd < 0)                                                         
                ft_error(strerror(errno), info.next->objet);
			utils->savefd = dup(utils->redir);
			dup2(fd, utils->redir);                 
			close(fd);
       // }                                                                       
        ft_redir(*info.next, env, utils);                  
    }
/*	else
		ft_redir_second(info, env, utils);*/
	return ;	
}
