/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:57:53 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/09 13:36:45 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_up(t_vars *v)
{
	if (v->map[v->y - 1][v->x] == '1')
		return ;
	else if (v->map[v->y][v->x] == 'E')
		mlx_put_image_to_window(v->mlx, v->win,
			v->o[0].i, ((v->x) * 64), ((v->y) * 64));
	else if (v->x == v->m->p && v->y - 1 == 2)
		ft_free(v);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->g[0].i, ((v->x) * 64), ((v->y) * 64));
	v->y = v->y - 1;
	if (v->sprite == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[0].i, ((v->x) * 64), ((v->y) * 64));
		v->sprite = 2;
	}
	else if (v->sprite != 1)
	{
		v->sprite = 1;
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[1].i, ((v->x) * 64), ((v->y) * 64));
	}
	v->cptmoove = v->cptmoove + 1;
}

void	ft_moove_down(t_vars *v)
{
	if (v->map[v->y + 1][v->x] == '1')
		return ;
	else if (v->map[v->y][v->x] == 'E')
		mlx_put_image_to_window(v->mlx, v->win,
			v->o[0].i, ((v->x) * 64), ((v->y) * 64));
	else if (v->x == v->m->p && v->y + 1 == 2)
		ft_free(v);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->g[0].i, ((v->x) * 64), ((v->y) * 64));
	v->y = v->y + 1;
	if (v->sprite == 1)
	{
		mlx_put_image_to_window(v->mlx,
			v->win, v->c[4].i, ((v->x) * 64), ((v->y) * 64));
		v->sprite = 2;
	}
	else if (v->sprite != 1)
	{
		v->sprite = 1;
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[5].i, ((v->x) * 64), ((v->y) * 64));
	}
	v->cptmoove = v->cptmoove + 1;
}

void	ft_moove_left(t_vars *v)
{
	if (v->map[v->y][v->x - 1] == '1')
		return ;
	else if (v->map[v->y][v->x] == 'E')
		mlx_put_image_to_window(v->mlx, v->win,
			v->o[0].i, ((v->x) * 64), ((v->y) * 64));
	else if (v->x - 1 == v->m->p && v->y == 2)
		ft_free(v);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->g[0].i, ((v->x) * 64), ((v->y) * 64));
	v->x = v->x - 1;
	if (v->sprite == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[2].i, ((v->x) * 64), ((v->y) * 64));
		v->sprite = 2;
	}
	else if (v->sprite != 1)
	{
		v->sprite = 1;
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[3].i, ((v->x) * 64), ((v->y) * 64));
	}
	v->cptmoove = v->cptmoove + 1;
}

void	ft_moove_right(t_vars *v)
{
	if (v->map[v->y][v->x + 1] == '1')
		return ;
	else if (v->map[v->y][v->x] == 'E')
		mlx_put_image_to_window(v->mlx, v->win,
			v->o[0].i, ((v->x) * 64), ((v->y) * 64));
	else if (v->x + 1 == v->m->p && v->y == 2)
		ft_free(v);
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->g[0].i, ((v->x) * 64), ((v->y) * 64));
	v->x = v->x + 1;
	if (v->sprite == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->c[6].i, ((v->x) * 64), ((v->y) * 64));
		v->sprite = 2;
	}
	else if (v->sprite != 1)
	{
		v->sprite = 1;
		mlx_put_image_to_window(v->mlx,
			v->win, v->c[7].i, ((v->x) * 64), ((v->y) * 64));
	}
	v->cptmoove = v->cptmoove + 1;
}
