/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:47:58 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 23:22:59 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_quotes_is_odd(char *str)
{
	int	dq;
	int	sq;

	dq = 0;
	sq = 0;
	while (*str)
	{
		if (*str == '\'')
			sq++;
		else if (*str == '"')
			dq++;
		str++;
	}
	if (sq % 2 != 0 || dq % 2 != 0)
		return (0);
	return (1);
}

int	ft_quote_overlap(char *str)
{
	int	dq;
	int	sq;
	int	last;

	dq = 0;
	sq = 0;
	last = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			if (last == doubleq && sq++ % 2 == 1)
				return (1);
			last = ft_check_the_simple(last, sq);
		}
		else if (*str == '"')
		{
			if (last == simpleq && dq % 2 == 1)
				return (1);
			dq++;
			last = ft_check_the_double(last, dq);
		}
		str++;
	}
	return (0);
}

int	ft_check_and_format(t_data *data)
{
	if (ft_quotes_is_odd(data->buffer))
	{
		if (!ft_quote_overlap(data->buffer))
		{
			if (ft_strchr(data->buffer, '$'))
				ft_fetch_env_2(data, 0);
			if (data->used % 2 == 0)
				data->used += ARGS;
			data->args = ft_split(data->buffer, ' ');
			ft_get_pathfile_2(data, 0);
			return (1);
		}
	}
	free_matrix(data->args);
	free(data->buffer);
	data->used -= (ARGS + BUFF);
	return (0);
}

void	ft_get_pathfile(t_data *data)
{
	char	*no_change;
	char	*add_path;

	no_change = ft_strdup(data->args[0]);
	add_path = ft_strjoin("/usr/bin/", data->args[0]);
	if (!access(no_change, F_OK))
		data->pathfile = ft_strdup(no_change);
	else if (!access(add_path, F_OK))
		data->pathfile = ft_strdup(add_path);
	else
		data->pathfile = ft_strdup(no_change);
	free(no_change);
	free(add_path);
	data->used += 2;
}

void	ft_get_pathfile_2(t_data *data, int i)
{
	char	**paths;
	char	*name;
	char	*fullname;
	int		found;

	found = 0;
	paths = ft_split(getenv("PATH"), ':');
	name = ft_strjoin("/", data->args[0]);
	while (i < ft_matrix_len(paths))
	{
		fullname = ft_strjoin(paths[i], name);
		if (!access(fullname, F_OK))
		{
			data->pathfile = ft_strdup(fullname);
			free(fullname);
			found = 1;
			break ;
		}
		i++;
		free(fullname);
	}
	if (!found)
		data->pathfile = ft_strdup(data->args[0]);
	ft_end_the_check(paths, name, data);
}
