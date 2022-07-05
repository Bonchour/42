/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:43:04 by amorel            #+#    #+#             */
/*   Updated: 2022/04/05 15:18:03 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;

	if (c > 256)
		c -= 256;
	found = NULL;
	while (*s)
	{
		if (*s == c)
			found = (char *) s;
		s++;
	}
	if (c == 0)
		found = (char *) s;
	return (found);
}
