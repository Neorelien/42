/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:42:30 by awery             #+#    #+#             */
/*   Updated: 2020/12/22 18:37:45 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

static void	ft_rm_malloc_ptf(int malloc_to_rm, char *str)
{
	if (malloc_to_rm)
		free(str);
}

static void	ft_display_str(int flag, char *str, int *size, int strlengh)
{
	if ((((flag) | (e_flagptf_point)) == flag))
		ft_putstr_fd(str, 1, size[1]);
	else
		ft_putstr_fd(str, 1, strlengh);
}

void		ft_is_s_ptf(int flag, int *size, va_list *arg)
{
	int		strlengh;
	char	*str;
	int		malloc_to_rm;

	str = (char*)va_arg(*arg, char*);
	malloc_to_rm = 0;
	if (str == NULL && (malloc_to_rm = 1))
		str = ft_strdup("(null)");
	strlengh = ft_strlen(str);
	if (((flag) | (e_flagptf_minus)) == flag)
		ft_display_str(flag, str, size, strlengh);
	if (strlengh < size[1] || (((flag) | (e_flagptf_point)) != flag))
		while (size[0]-- - strlengh > 0)
			ft_putchar_fd(' ', 1);
	else
		while (size[0]-- - size[1] > 0)
			ft_putchar_fd(' ', 1);
	if (((flag) | (e_flagptf_minus)) != flag)
		ft_display_str(flag, str, size, strlengh);
	ft_rm_malloc_ptf(malloc_to_rm, str);
}
