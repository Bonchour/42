/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:22:08 by hde-min           #+#    #+#             */
/*   Updated: 2022/07/05 13:31:58 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_end_the_check(char **path, char *name, t_data *data)
{
	free_matrix(path);
	free(name);
	data->used += PATH;
}

int	ft_check_the_simple(int last, int sq)
{
	if (sq % 2 == 1)
		last = simpleq;
	else
		last = doubleq;
	return (last);
}

int	ft_check_the_double(int last, int dq)
{
	if (dq % 2 == 1)
		last = doubleq;
	else
		last = simpleq;
	return (last);
}
