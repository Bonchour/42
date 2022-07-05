/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_ft-strncmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:26:47 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 22:49:55 by amorel           ###   ########.fr       */
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
	while (i < n)
	{
		if (*ps1 < *ps2 || (*ps1 == 0 && *ps2 != 0))
			return (-1);
		else if (*ps1 > *ps2 || (*ps2 == 0 && *ps1 != 0))
			return (1);
		else if (*ps1 == *ps2)
		{
			ps1++;
			ps2++;
			i++;
		}
	}
	return (0);
}
