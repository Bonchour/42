/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:59:13 by amorel            #+#    #+#             */
/*   Updated: 2022/07/12 12:16:32 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!s1 || !s2)
		return (1);
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while (ps1[i] == ps2[i] && (ps1[i] || ps2[i]))
		i++;
	if (ps1[i] - ps2[i] < 0)
		return (-1);
	else if (ps1[i] - ps2[i] > 0)
		return (1);
	else
		return (0);
}
