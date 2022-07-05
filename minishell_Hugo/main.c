/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:57:01 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 22:05:32 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.used = 0;
	data.pathfile = NULL;
	data.args = NULL;
	(void)argv[argc];
	set_ttys();
	data.sigact = ft_init_sigset();
	data.envp = ft_copy_env(envp);
	while (1)
	{
		sigaction(SIGINT, &data.sigact, NULL);
		sigaction(SIGQUIT, &data.sigact, NULL);
		data.buffer = readline("Yes master? > ");
		if (data.used / BUFF == 0)
			data.used += BUFF;
		add_history(data.buffer);
		if (!data.buffer)
			ft_exit(&data);
		if (ft_check_and_format(&data))
			ft_parse(&data);
		else
			free_all(&data);
	}
	return (0);
}
