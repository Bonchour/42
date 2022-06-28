/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:31:25 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/07 12:55:05 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_matrice_2(t_vars *v, t_map_error *m, char *buff, t_matrice mat)
{
	if (buff[mat.k] == '\n' || buff[mat.k] == 0)
		v->map[mat.i][mat.j] = '\0';
	else
	{
		if (buff[mat.k] == 'P' && v->sprite == 1)
		{
			v->x = mat.j;
			v->y = mat.i;
			v->sprite = 2;
		}
		if (buff[mat.k] == 'E' && m->p == -1)
		{
			v->map[mat.i][mat.j] = buff[mat.k];
			m->p = 1;
		}
		else if (buff[mat.k] == 'E' && m->p == 1)
			v->map[mat.i][mat.j] = '0';
		else
			v->map[mat.i][mat.j] = buff[mat.k];
	}
}

void	ft_file_matrice(t_vars *v, t_map_error *m, char *buff)
{
	t_matrice	matrice;

	matrice.k = 0;
	matrice.i = 0;
	matrice.j = 0;
	while (buff[matrice.k] != '\0')
	{
		while (matrice.j < m->cpt2)
		{
			ft_file_matrice_2(v, m, buff, matrice);
			matrice.k++;
			matrice.j++;
		}
		matrice.i++;
		matrice.j = 0;
	}
	free(buff);
}

void	ft_matrice(t_vars *vars, t_map_error *m)
{
	int		i;
	char	*buff;
	int		fd;

	i = 0;
	while (i < m->ligne)
	{
		vars->map[i] = malloc(sizeof(char) * (m->cpt2));
		i++;
	}
	vars->map[i] = NULL;
	fd = open(m->map, O_RDONLY);
	buff = malloc(sizeof(char) * (m->ligne * m->cpt2 + 1));
	i = read(fd, buff, ((m->ligne) * (m->cpt2)));
	if (i < 0)
	{
		free(buff);
		return ;
	}
	buff[i] = 0;
	close(fd);
	ft_file_matrice(vars, m, buff);
}
