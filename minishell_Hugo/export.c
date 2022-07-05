/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:37:09 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 23:03:47 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_export(t_data *data)
{
	int		len;
	int		i;
	char	**envp;

	if (ft_env_exists(data->envp, data->args[1]))
		ft_env_change(data);
	else
	{
		i = 0;
		len = ft_matrix_len(data->envp);
		envp = ft_calloc(len + 2, sizeof(char *));
		while (i < len)
		{
			envp[i] = ft_strdup(data->envp[i]);
			i++;
		}
		envp[i] = ft_strdup(data->args[1]);
		envp[i + 1] = NULL;
		free_matrix(data->envp);
		data->envp = envp;
	}
}
