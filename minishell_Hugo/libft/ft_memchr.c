/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:30:23 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 17:41:30 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	key;

	i = 0;
	key = (unsigned char) c;
	ps = (unsigned char *) s;
	while (i < n)
	{
		if (ps[i] == key)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}
