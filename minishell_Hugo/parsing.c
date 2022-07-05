/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 20:18:13 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 22:08:06 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_parse(t_data *data)
{
	pid_t	pid;

	ft_parse_2(data);
	if (!ft_strcmp(data->args[0], "echo"))
		ft_echo(data->args);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			execve(data->pathfile, data->args, data->envp);
			free_all(data);
			free_matrix(data->envp);
			exit (-1);
		}
		wait(NULL);
	}
	free_all(data);
}

void	ft_parse_2(t_data *data)
{
	if (!ft_strcmp(data->buffer, "exit"))
		ft_exit(data);
	else if (!ft_strcmp(data->args[0], "cd"))
		ft_cd(data->args[1]);
	else if (!ft_strcmp(data->buffer, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(data->args[0], "export"))
		ft_export(data);
	else if (!ft_strcmp(data->args[0], "unset"))
		ft_unset(data);
	else if (!ft_strcmp(data->buffer, "env"))
		ft_env(data->envp);
	return ;
}
