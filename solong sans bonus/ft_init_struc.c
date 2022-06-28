/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:35:14 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/07 12:22:29 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_struc(t_vars *v, t_map_error *m, char *argv)
{
	v->mlx = NULL;
	v->win = NULL;
	v->f = NULL;
	v->c = NULL;
	v->g = NULL;
	v->o = NULL;
	v->x = 0;
	v->y = 0;
	v->cptmoove = 0;
	v->sprite = 1;
	v->map = NULL;
	m->cpt = 0;
	m->cpt2 = 0;
	m->ligne = 0;
	m->ligne2 = 0;
	m->p = 0;
	m->c = 0;
	m->e = 0;
	m->leftwall = 0;
	m->save = '1';
	m->map = argv;
}
