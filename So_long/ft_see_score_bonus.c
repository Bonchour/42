/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:30:03 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/09 11:37:54 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_see(int nb, int i, t_vars *v)
{
	int	ligne;

	ligne = (v->m->ligne * 32) - i * 32;
	mlx_put_image_to_window(v->mlx, v->win, v->o[nb + 4].i, (ligne), (0));
}

void	ft_see_score(int nb, t_vars *v)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = nb;
	if (nb >= 10)
		ft_see_score(nb / 10, v);
	nb %= 10;
	while (tmp >= 10)
	{
		i--;
		tmp /= 10;
	}
	if (nb < 10)
		ft_see(nb, i, v);
}
