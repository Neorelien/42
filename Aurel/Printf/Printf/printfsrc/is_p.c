/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:28:14 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/05 23:52:24 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

void	ppt_ptf(int flag, unsigned long long oradress, int *size, char *str_adr)
{
	ft_putstr_fd("0x", 1, 2);
	if (((flag) | (e_flagptf_point)) == flag && oradress == 0)
		while (size[1]--)
			ft_putchar_fd('0', 1);
	else
			ft_putstr_fd(str_adr, 1, 100);
}

void	ft_is_p_ptf(int flag, int *size, va_list *arg)
{
	unsigned long long	origin_adresse;
	char				*str_adress;
	char				*temp;
	int					adresslen;

	origin_adresse = (unsigned long long)va_arg(*arg, unsigned long long);
	temp = ft_itoa(origin_adresse);
	str_adress = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	adresslen = ft_strlen(str_adress) + 2;
	free(temp);
	if (((flag) | (e_flagptf_point)) == flag && origin_adresse == 0)
		size[0] += 1 - size[1];
	if (((flag) | (e_flagptf_minus)) == flag)
		ppt_ptf(flag, origin_adresse, size, str_adress);
	while ((size[0]-- - adresslen) > 0)
		ft_putchar_fd(' ', 1);
	if (((flag) | (e_flagptf_minus)) != flag)
		ppt_ptf(flag, origin_adresse, size, str_adress);
	free(str_adress);
}
