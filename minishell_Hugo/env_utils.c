/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:48:14 by amorel            #+#    #+#             */
/*   Updated: 2022/07/05 12:34:50 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_env_change(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->envp[i])
	{
		while (data->envp[i][j] == data->args[1][j]
			&& data->envp[i][j] && data->args[1][j])
		{
			if (data->envp[i][j] == '=' && data->args[1][j] == '=')
			{
				free(data->envp[i]);
				data->envp[i] = strdup(data->args[1]);
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

char	*ft_get_varname(char *str)
{
	char	*name;
	int		i;

	if (!str)
		return (str);
	i = 0;
	while (str[i] != ' ' && str[i] != '\'' && str[i] != '"' && str[i]
		&& str[i] != '$')
		i++;
	name = ft_calloc(sizeof(char), i + 1);
	i = 0;
	while (str[i] != ' ' && str[i] != '\'' && str[i] != '"' && str[i]
		&& str[i] != '$')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = 0;
	return (name);
}

void	ft_fetch_env_2(t_data *data, size_t i)
{
	t_utils	*u;

	u = malloc(sizeof(t_utils));
	u->dq = 0;
	u->sq = 0;
	u->new_str = NULL;
	while (i < ft_strlen(data->buffer))
	{
		if (data->buffer[i] == '"')
			ft_double_quote(u);
		else if (data->buffer[i] == '\'')
			ft_simple_quote(u);
		if (u->sq % 2 == 0 && u->dq % 2 == 0)
			u->first = 0;
		u->name = ft_get_varname(&data->buffer[i + 1]);
		if (data->buffer[i] == '$' && (u->first == doubleq || u->first == 0)
			&& ft_env_check(data->envp, u->name))
			i = ft_join_env_utils(u, i, data);
		else
			i = ft_already_here(u, i, data);
		free(u->name);
	}
	ft_i_need_to_free(u, data);
}

char	*ft_getenv(char **envp, char *str)
{
	int		i;
	int		j;
	int		found;
	char	*value;

	i = 0;
	j = 0;
	found = 0;
	while (envp[i] && !found)
	{
		j = 0;
		while (envp[i][j] == str[j] && envp[i][j] && !found)
			j++;
		if (envp[i][j] == '=' && !str[j])
		{
			j++;
			value = ft_strdup(&envp[i][j]);
		}
		i++;
	}
	i--;
	return (value);
}

char	**ft_copy_env(char **envp)
{
	int		i;
	char	**copy;

	i = 0;
	copy = ft_calloc((ft_matrix_len(envp) + 1), sizeof(char *));
	while (i < ft_matrix_len(envp))
	{
		copy[i] = ft_strdup(envp[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
