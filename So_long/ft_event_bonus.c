/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:10:04 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/09 14:21:24 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove_rats(int i, int j, t_vars *v, int cpt)
{
	t_img	*o;
	t_img	*g;

	o = v->o;
	g = v->g;
	if (cpt == 1)
		mlx_put_image_to_window(v->mlx, v->win, o[1].i, (j * 64), (i * 64));
	else
		mlx_put_image_to_window(v->mlx, v->win, g[5].i, (j * 64), (i * 64));
}

void	ft_moove_door(int i, int j, t_vars *v, int cpt)
{
	t_img	*o;
	t_img	*g;

	o = v->o;
	g = v->g;
	if (cpt == 1)
		mlx_put_image_to_window(v->mlx, v->win, o[0].i, (j * 64), (i * 64));
	else
		mlx_put_image_to_window(v->mlx, v->win, g[4].i, (j * 64), (i * 64));
}

void	ft_anim_map(t_vars *v, int cpt)
{
	int	j;
	int	i;

	i = 0;
	while (i < v->m->ligne)
	{
		j = 0;
		while (v->map[i][j])
		{
			if (v->map[i][j] == 'C')
				ft_moove_rats(i, j, v, cpt);
			else if (v->map[i][j] == 'E' && (i != v->y || j != v->x))
				ft_moove_door(i, j, v, cpt);
			j++;
		}
		i++;
	}
}

void	ft_anim_doggo(t_vars *v, int doggo)
{
	static int	i;
	static int	d;

	if (doggo == 0)
		i = ft_where_dog(i, v);
	else
	{
		if (d == 0)
		{
			if (v->map[2][i + 1] != '1')
				i = ft_anim_doggo_right(v, i, doggo);
			else
				d = 1;
		}
		else
		{	
			if (v->map[2][i - 1] != '1')
				i = ft_anim_doggo_left(v, i, doggo);
			else
				d = 0;
		}
	}
	v->m->p = i;
}

int	ft_animations(t_vars *vars)
{
	static int	x;
	static int	cpt;
	static int	doggo;

	if (cpt == 0)
		cpt = 1;
	x++;
	if (x == 50001)
	{
		x = 0;
		ft_anim_doggo(vars, doggo);
		doggo++;
		if (doggo == 5)
			doggo = 1;
	}
	if (x == 50000)
	{
		ft_anim_map(vars, cpt);
		cpt *= -1;
	}
	if (vars->x == vars->m->p && vars->y == 2)
		ft_free(vars);
	return (0);
}
