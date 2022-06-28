/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:34:15 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/10 11:38:59 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_map(int e, int fd, t_vars *v)
{
	int	i;

	i = 1;
	if (e == -1)
		i = write(1, "error width\n", 12);
	else if (e == -2)
		i = write(1, "error lign\n", 11);
	else if (e == -3)
		i = write(1, "error charac\n", 13);
	else if (e == -4)
		i = write(1, "error lost game\n", 16);
	else if (e == -5)
		i = write(1, "error wall\n", 11);
	else if (e == -6)
		i = write(1, "error fd\n", 9);
	if (i != 0)
	{
		free(v->m);
		free(v);
		if (fd > 0)
			close(fd);
		exit(0);
	}
}

void	ft_test_map_2(int fd, t_vars *v)
{	
	t_map_error		*m;
	char			buff[1];
	int				i;

	i = 0;
	m = v->m;
	fd = open(m->map, O_RDONLY);
	while (i < (m->ligne - 1) && read(fd, buff, 1))
	{
		if (buff[0] == '\n')
			i++;
	}
	while (read(fd, buff, 1) > 0)
	{
		if (buff[0] != '1' && buff[0] != '\n' && buff[0] != '\0')
			ft_error_map(-5, fd, v);
	}
	if (m->cpt2 <= 2 || m->ligne <= 2)
		ft_error_map(-2, fd, v);
	if (m->p < 1 || m->c < 1 || m->e < 1)
		ft_error_map(-4, fd, v);
	close(fd);
}

void	ft_test_map_3(t_vars *v, char buff, int fd)
{
	t_map_error	*m;

	m = v->m;
	if (m->cpt2 == 0 && buff != '1' && buff != '\n')
		ft_error_map(-5, fd, v);
	if (buff != '1' && buff != '0'
		&& buff != 'C' && buff != 'E'
		&& buff != 'P' && buff != '\n')
		ft_error_map(-3, fd, v);
	if (buff == 'P')
		m->p = m->p + 1;
	if (buff == 'C')
		m->c = m->c + 1;
	if (buff == 'E')
		m->e = m->e + 1;
	m->cpt++;
}

void	ft_test_map(t_vars *v)
{
	t_map_error	*m;
	int			fd;
	char		buff[1];

	m = v->m;
	fd = open(m->map, O_RDONLY);
	if (fd < 0)
		ft_error_map(-6, fd, v);
	while (read(fd, buff, 1) > 0)
	{
		if (m->leftwall == 1 && buff[0] != '1')
			ft_error_map(-5, fd, v);
		else
			m->leftwall = 0;
		ft_test_map_3(v, buff[0], fd);
		if (buff[0] == '\n')
			ft_test_map_4(v, fd);
		if (m->save != '1' && buff[0] == '\n')
			ft_error_map(-5, fd, v);
		m->save = buff[0];
	}
	close(fd);
	ft_test_map_2(fd, v);
}
