/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:09:16 by amorel            #+#    #+#             */
/*   Updated: 2022/06/29 22:19:44 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

struct sigaction	ft_init_sigset(void)
{
	struct sigaction	sigact;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigaddset(&sigset, SIGQUIT);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_mask = sigset;
	sigact.sa_sigaction = &ft_sig_handler;
	return (sigact);
}
