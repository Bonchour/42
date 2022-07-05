/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:27:32 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 22:49:33 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_env_exists(char **envp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		while (envp[i][j] == str[j] && envp[i][j] && str[j])
		{
			if (envp[i][j + 1] == '=' && str[j + 1] == '=')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_env_check(char **envp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] == str[j] && envp[i][j])
			j++;
		if (envp[i][j] == '=' && !str[j])
			return (1);
		i++;
	}
	return (0);
}
