/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_map_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:08:01 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/09 11:38:15 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_test_map_4(t_vars *v, int fd)
{
	t_map_error	*m;

	m = v->m;
	m->leftwall = 1;
	m->ligne++;
	if (m->cpt != m->cpt2 && m->cpt2 != 0)
		ft_error_map(-1, fd, v);
	m->cpt2 = m->cpt;
	m->cpt = 0;
}
