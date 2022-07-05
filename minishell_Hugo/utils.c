/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:21:56 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 22:07:21 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	free_all(t_data *data)
{
	if (data->used / BUFF)
	{
		free(data->buffer);
		data->used -= BUFF;
	}
	if (data->used / PATH)
	{
		free(data->pathfile);
		data->used -= PATH;
	}
	if (data->used / ARGS)
	{
		free_matrix(data->args);
		data->used -= ARGS;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (i < ft_matrix_len(matrix))
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	set_ttys(void)
{
	char	**args;
	int		pid;
	int		i;

	i = 0;
	args = ft_split("stty -ctlecho", ' ');
	pid = fork();
	if (pid == 0)
		execve("/usr/bin/stty", args, NULL);
	wait(NULL);
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	ft_matrix_len(char **envp)
{
	int	l;

	l = 0;
	while (envp[l])
		l++;
	return (l);
}

void	ft_free(char **strmatrix, int j)
{
	while (j-- > 0)
		free(strmatrix[j]);
	free(strmatrix);
}
