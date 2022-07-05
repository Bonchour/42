/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:36:42 by amorel            #+#    #+#             */
/*   Updated: 2022/06/26 16:12:57 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_cd(char *str)
{
	if (!str)
		str = getenv("HOME");
	if (chdir((const char *)str) == -1)
		printf("invalid path\n");
}
