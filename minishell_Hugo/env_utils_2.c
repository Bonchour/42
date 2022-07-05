/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <hde-min@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:35:35 by hde-min           #+#    #+#             */
/*   Updated: 2022/07/05 13:23:41 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_double_quote(t_utils *u)
{
	if (u->sq % 2 == 0 && u->dq % 2 == 0)
		u->first = doubleq;
	u->dq++;
}

void	ft_simple_quote(t_utils *u)
{
	if (u->sq % 2 == 0 && u->dq % 2 == 0)
		u->first = simpleq;
	u->sq++;
}

int	ft_join_env_utils(t_utils *u, int i, t_data *data)
{
	i++;
	u->tmp = ft_strjoin(u->new_str,
			u->new_name = ft_getenv(data->envp, u->name));
	free(u->new_name);
	i += ft_strlen(u->name);
	free(u->new_str);
	u->new_str = ft_strdup(u->tmp);
	free(u->tmp);
	return (i);
}

int	ft_already_here(t_utils *u, int i, t_data *data)
{
	u->tmp = ft_strlcat(u->new_str, &data->buffer[i], 1);
	u->new_str = ft_strdup(u->tmp);
	free(u->tmp);
	i++;
	return (i);
}

void	ft_i_need_to_free(t_utils *u, t_data *data)
{
	free(data->buffer);
	data->buffer = ft_strdup(u->new_str);
	free(u->new_str);
	free(u);
}
