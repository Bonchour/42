/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:26:47 by amorel            #+#    #+#             */
/*   Updated: 2022/07/12 12:15:56 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while (ps1[i] == ps2[i] && ps1[i + 1] && ps2[i + 1] && i < n)
		i++;
	if (ps1[i] - ps2[i] < 0)
		return (-1);
	else if (ps1[i] - ps2[i] > 0)
		return (1);
	else
		return (0);
}
