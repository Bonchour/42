/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:23:48 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/08 15:37:51 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_init_object(t_vars *vars)
{
	t_img	*o;
	int		i;

	o = vars->o;
	ft_init_image_2(o);
	i = -1;
	while (++i < 4)
	{
		o[i].x = 64;
		o[i].y = 64;
		o[i].i = mlx_xpm_file_to_image(vars->mlx, o[i].p, &o[i].x, &o[i].y);
	}
	i--;
	while (++i < 14)
	{
		o[i].x = 32;
		o[i].y = 32;
		o[i].i = mlx_xpm_file_to_image(vars->mlx, o[i].p, &o[i].x, &o[i].y);
	}
}

void	ft_init_ground(t_vars *vars)
{
	t_img	*g;
	int		i;

	g = vars->g;
	g[0].p = "Images/ground.xpm/sol1.xpm";
	g[1].p = "Images/ground.xpm/sol2.xpm";
	g[2].p = "Images/ground.xpm/sol3.xpm";
	g[3].p = "Images/ground.xpm/spawn.xpm";
	g[4].p = "Images/animation.xpm/porte_2_animation.xpm";
	g[5].p = "Images/animation.xpm/rat2.xpm";
	g[6].p = "Images/dog.xpm/1.xpm";
	g[7].p = "Images/dog.xpm/2.xpm";
	g[8].p = "Images/dog.xpm/3.xpm";
	g[9].p = "Images/dog.xpm/4.xpm";
	i = -1;
	while (++i < 10)
	{
		g[i].x = 64;
		g[i].y = 64;
		g[i].i = mlx_xpm_file_to_image(vars->mlx, g[i].p, &g[i].x, &g[i].y);
	}
}

void	ft_init_fence(t_vars *vars)
{
	t_img	*f;
	int		i;

	f = vars->f;
	f[0].p = "Images/fence.xpm/barrierre.xpm";
	f[1].p = "Images/fence.xpm/barrierre2.xpm";
	f[2].p = "Images/fence.xpm/barrierrecoterdroit.xpm";
	f[3].p = "Images/fence.xpm/barrierrecoter.xpm";
	f[4].p = "Images/fence.xpm/barrierre5.xpm";
	f[5].p = "Images/fence.xpm/barrierre6.xpm";
	f[6].p = "Images/fence.xpm/barrierre7.xpm";
	f[7].p = "Images/fence.xpm/barrierre8.xpm";
	i = -1;
	while (++i < 8)
	{
		f[i].x = 64;
		f[i].y = 64;
		f[i].i = mlx_xpm_file_to_image(vars->mlx, f[i].p, &f[i].x, &f[i].y);
	}
}

void	ft_init_cat(t_vars *vars)
{
	t_img	*c;
	int		i;

	c = vars->c;
	c[0].p = "Images/cat.xpm/Catto.xpm";
	c[1].p = "Images/cat.xpm/Catto0.xpm";
	c[2].p = "Images/cat.xpm/Catto1.xpm";
	c[3].p = "Images/cat.xpm/Catto2.xpm";
	c[4].p = "Images/cat.xpm/Catto3.xpm";
	c[5].p = "Images/cat.xpm/Catto4.xpm";
	c[6].p = "Images/cat.xpm/Catto5.xpm";
	c[7].p = "Images/cat.xpm/Catto6.xpm";
	i = -1;
	while (++i < 8)
	{
		c[i].x = 64;
		c[i].y = 64;
		c[i].i = mlx_xpm_file_to_image(vars->mlx, c[i].p, &c[i].x, &c[i].y);
	}
}

void	ft_init_image(t_vars *vars)
{
	vars->c = malloc(sizeof(t_img) * 8);
	vars->f = malloc(sizeof(t_img) * 8);
	vars->g = malloc(sizeof(t_img) * 10);
	vars->o = malloc(sizeof(t_img) * 14);
	ft_init_cat(vars);
	ft_init_fence(vars);
	ft_init_ground(vars);
	ft_init_object(vars);
}
