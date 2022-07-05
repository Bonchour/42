/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:47:21 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 19:25:46 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	if (!(unsigned char *) s1 && !(unsigned char *) s2)
		return (0);
	ps1 = (unsigned char *) s1;
	ps2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (*ps1 < *ps2)
			return (-1);
		else if (*ps1 > *ps2)
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
