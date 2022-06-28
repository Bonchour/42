/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:39:04 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/07 13:16:39 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_file_0(int i, int j, t_vars *v)
{
	t_img	*g;

	g = v->g;
	i = i + 1;
	mlx_put_image_to_window(v->mlx, v->win,
		g[2].i, ((i - 3) * 64), ((j - 1) * 64));
}

void	ft_file_1(int i, int j, t_vars *v)
{
	t_img	*o;

	o = v->o;
	i = i + 1;
	mlx_put_image_to_window(v->mlx, v->win,
		o[2].i, ((i - 3) * 64), ((j - 1) * 64));
}

void	ft_file_e(int i, int j, t_vars *v)
{
	t_img	*o;

	o = v->o;
	i = i + 1;
	mlx_put_image_to_window(v->mlx, v->win,
		o[0].i, ((i - 3) * 64), ((j - 1) * 64));
}

void	ft_file_c(int i, int j, t_vars *v)
{
	t_img	*o;

	o = v->o;
	i = i + 1;
	mlx_put_image_to_window(v->mlx, v->win,
		o[1].i, ((i - 3) * 64), ((j - 1) * 64));
}

void	ft_file_p(int i, int j, t_vars *v)
{
	t_img	*g;

	g = v->g;
	i = i + 1;
	mlx_put_image_to_window(v->mlx, v->win,
		g[3].i, ((i - 3) * 64), ((j - 1) * 64));
}
