/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:37:22 by amorel            #+#    #+#             */
/*   Updated: 2022/06/29 23:33:57 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_unset(t_data *data)
{
	char	**new_envp;
	int		i;
	int		j;
	int		found;

	i = 0;
	j = 0;
	found = 0;
	new_envp = ft_calloc((ft_matrix_len(data->envp) + 1), sizeof(char *));
	while (data->envp[i])
	{
		while (data->envp[i][j] == data->args[1][j] && data->envp[i][j]
			&& data->args[1][j] && !found)
		{
			if (data->envp[i][j + 1] == '=' && data->args[1][j + 1] == 0)
				found = 1;
			j++;
		}
		new_envp[i] = ft_strdup(data->envp[i - found]);
		i++;
		j = 0;
	}
	new_envp[i] = NULL;
	free_matrix(data->envp);
	data->envp = new_envp;
}
