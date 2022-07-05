/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:36:27 by amorel            #+#    #+#             */
/*   Updated: 2022/06/29 20:00:00 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_endl(char **args)
{
	int	i;

	i = 0;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	printf("\n");
}

static void	ft_end(char **args)
{
	int	i;

	i = 1;
	while (args[++i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
}

void	ft_echo(char **args)
{
	if (args[1])
	{
		if (ft_strcmp(args[1], "-n") == 0)
			ft_end(args);
		else
			ft_endl(args);
	}
	else
		printf("\n");
}
