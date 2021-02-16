/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 14:45:45 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/12 14:46:53 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void			orientation_suppor(int *pos, int *range, int *i)
{
	if (range[0] < range[1])
		*i = pos[0];
	else
		*i = pos[1];
}
