/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:14 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/10 11:43:09 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_free_image(t_vars *v)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		mlx_destroy_image(v->mlx, v->f[i].i);
		mlx_destroy_image(v->mlx, v->c[i].i);
	}
	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(v->mlx, v->g[i].i);
		mlx_destroy_image(v->mlx, v->o[i].i);
	}
	free(v->c);
	free(v->f);
	free(v->g);
	free(v->o);
}

void	ft_free_map(char **m)
{
	int	i;

	i = 0;
	while (m[i] != NULL)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

void	ft_free(t_vars *vars)
{
	ft_free_map(vars->map);
	ft_free_image(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->m);
	free(vars->mlx);
	free(vars);
	exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		ft_free(vars);
	else if (keycode == XK_w || keycode == XK_Up)
		ft_moove_up(vars);
	else if (keycode == XK_a || keycode == XK_Left)
		ft_moove_left(vars);
	else if (keycode == XK_s || keycode == XK_Down)
		ft_moove_down(vars);
	else if (keycode == XK_d || keycode == XK_Right)
		ft_moove_right(vars);
	if (vars->map[vars->y][vars->x] == 'C')
	{
		vars->map[vars->y][vars->x] = '0';
		vars->m->c = vars->m->c - 1;
	}
	if (vars->map[vars->y][vars->x] == 'E' && vars->m->c == 0)
		ft_free(vars);
	if (vars->m->leftwall != -1)
	{
		ft_putnbr(vars->cptmoove);
		if (!write(1, "\n", 1))
			return (0);
	}
	vars->m->leftwall = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;

	if (argc == 2)
	{
		ft_check_ber(argv[1]);
		vars = malloc(sizeof(t_vars));
		vars->m = malloc(sizeof(t_map_error));
		ft_init_struc(vars, vars->m, argv[1]);
		ft_test_map(vars);
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx,
				((vars->m->cpt2 - 1) * 64), (vars->m->ligne * 64), "Game");
		ft_init_image(vars);
		ft_wall(vars, vars->m);
		ft_file_map(vars, vars->m);
		vars->map = malloc(sizeof(char *) * (vars->m->ligne + 1));
		ft_matrice(vars, vars->m);
		mlx_key_hook(vars->win, key_hook, vars);
		mlx_hook(vars->win, 17, 1L >> 2, ft_mouse_hook, vars);
		mlx_loop(vars->mlx);
	}
	return (-10);
}
