/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:26:32 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/07 13:29:02 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_file_map_3(t_vars *v, t_fm fm)
{
	if (fm.buff[fm.i] == 'C')
		ft_file_c(fm.cpt, fm.j, v);
	else if (fm.buff[fm.i] == 'P')
	{
		if (v->m->p != -1)
		{
			v->m->p = -1;
			ft_file_p(fm.cpt, fm.j, v);
		}
		else
			ft_file_0(fm.cpt, fm.j, v);
	}
}

void	ft_file_map_2(t_vars *v, t_fm fm)
{
	if (fm.buff[fm.i] == '0')
		ft_file_0(fm.cpt, fm.j, v);
	else if (fm.buff[fm.i] == '1'
		&& (fm.buff[fm.i + 1] != '\n' && fm.buff[fm.i - 1] != '\n'))
		ft_file_1(fm.cpt, fm.j, v);
	else if (fm.buff[fm.i] == 'E')
	{
		if (v->m->e != -1)
		{
			v->m->e = -1;
			ft_file_e(fm.cpt, fm.j, v);
		}
		else
			ft_file_0(fm.cpt, fm.j, v);
	}
}

void	ft_file_map(t_vars *v, t_map_error *m)
{
	t_fm	fm;

	fm.cpt = 0;
	fm.j = 1;
	fm.i = 0;
	fm.fd = open(m->map, O_RDONLY);
	fm.buff = malloc(sizeof(char) * ((m->ligne) * (m->cpt2)));
	if (read(fm.fd, fm.buff, ((m->ligne) * (m->cpt2))) < 0)
		return ;
	while (fm.buff[fm.i] != '\n')
		fm.i = fm.i + 1;
	while (fm.i != (((m->ligne - 1) * (m->cpt2))))
	{
		if (fm.buff[fm.i] == '\n')
		{
			fm.cpt = 1;
			fm.j = fm.j + 1;
		}
		ft_file_map_2(v, fm);
		ft_file_map_3(v, fm);
		fm.i++;
		fm.cpt++;
	}
	close(fm.fd);
	free (fm.buff);
}
