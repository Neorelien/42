/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:20:01 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/27 01:04:50 by aurelien         ###   ########.fr       */
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

void	ft_redir(t_parsing info, char **env, t_utils *utils)
{
	int sep;
	int flag_pipe;
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
	flag_pipe = ft_next_is_pipe(info, env, utils, 0);
	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return ;
    else if (sep == 2)
        ft_pipe_settings(utils);
    else if (sep == 3)                                                          
    {                                                                           
        if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
            ft_reroll(info, env, utils);                                        
        else                                                                    
        {	
            fd = open(info.next->objet, O_WRONLY | O_CREAT, 0644 | O_DIRECTORY);
            if (fd < 0)
                ft_error(strerror(errno), info.next->objet);
			utils->savefd = dup(1);
			dup2(fd, 1);
        }                                                                       
        ft_redir(*info.next, env, utils);                  
    }                                                                           
    else if (sep == 4)
	{
		if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
            ft_reroll(info, env, utils);                                        
        else                                                                    
        {                      
            fd = open(info.next->objet, O_RDONLY);
			utils->savefdout = dup(0);
			dup2(fd, 0);
        }	
        ft_redir(*info.next, env, utils);      
	}
    else if (sep == 5)                                                          
    {                                                                           
        if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
            ft_reroll(info, env, utils);                                        
        else                                                                    
        {                      
            fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644 | O_DIRECTORY);
            if (fd < 0)                                                         
                ft_error(strerror(errno), info.next->objet);
			utils->savefd = dup(1);
			dup2(fd, 1);                 
        }                                                                       
        ft_redir(*info.next, env, utils);                  
    }	
/*	else
		ft_redir_second(info, env, utils);*/
	
}
