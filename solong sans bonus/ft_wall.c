/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:18:54 by hde-min           #+#    #+#             */
/*   Updated: 2022/05/31 15:11:22 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_2(t_vars *v, t_map_error *m)
{
	int		x;
	int		y;
	int		x2;
	int		i;
	t_img	*f;

	x = 0;
	x2 = 64 * (m->cpt2 - 2);
	y = 64;
	f = v->f;
	i = 0;
	while (i < m->ligne - 2)
	{
		mlx_put_image_to_window(v->mlx, v->win, f[3].i, x, y);
		mlx_put_image_to_window(v->mlx, v->win, f[3].i, x2, y);
		y = y + 64;
		i++;
	}
}

void	ft_put_coin(t_vars *v, t_map_error *m, t_img *f)
{
	mlx_put_image_to_window(v->mlx, v->win, f[7].i, 0, 0);
	mlx_put_image_to_window(v->mlx, v->win, f[6].i, ((m->cpt2 - 2) * 64), 0);
	mlx_put_image_to_window(v->mlx, v->win, f[4].i, 0, ((m->ligne - 1) * 64));
	mlx_put_image_to_window(v->mlx, v->win,
		f[5].i, (m->cpt2 - 2) * 64, ((m->ligne - 1) * 64));
}

void	ft_wall(t_vars *v, t_map_error *m)
{
	int		x;
	int		y;
	int		i;
	int		y2;
	t_img	*f;

	i = 0;
	x = 64;
	y = 0;
	f = v->f;
	y2 = (m->ligne - 1) * 64;
	ft_put_coin(v, m, f);
	while (i < m->cpt2 - 3)
	{
		mlx_put_image_to_window(v->mlx, v->win, f[i * 15 % 2].i, x, y);
		mlx_put_image_to_window(v->mlx, v->win, f[i * 41 % 2].i, x, y2);
		x = x + 64;
		i++;
	}
	ft_wall_2(v, m);
}
