/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:40:37 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/09 14:56:57 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_where_dog(int i, t_vars *v)
{
	while (v->map[2][i] == '1')
		i++;
	mlx_put_image_to_window(v->mlx, v->win,
		v->g[6].i, (i * 64), (2 * 64));
	return (i);
}

int	ft_anim_doggo_right(t_vars *v, int i, int doggo)
{
	t_img	*g;

	g = v->g;
	i++;
	mlx_put_image_to_window(v->mlx,
		v->win, g[doggo + 5].i, (i * 64), (2 * 64));
	mlx_put_image_to_window(v->mlx,
		v->win, g[2].i, ((i - 1) * 64), (2 * 64));
	return (i);
}

int	ft_anim_doggo_left(t_vars *v, int i, int doggo)
{
	t_img	*g;

	g = v->g;
	i--;
	mlx_put_image_to_window(v->mlx, v->win, g[doggo + 5].i,
		(i * 64), (2 * 64));
	mlx_put_image_to_window(v->mlx, v->win, g[2].i,
		((i + 1) * 64), (2 * 64));
	return (i);
}
