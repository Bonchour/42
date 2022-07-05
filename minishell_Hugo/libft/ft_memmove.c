/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:54:04 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 19:30:14 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	unsigned const char	*psrc;
	size_t				i;

	if (!dest && !src)
		return (dest);
	pdest = dest;
	psrc = src;
	i = 0;
	while (i < n)
	{
		if (dest < src)
		{
			pdest[i] = psrc[i];
			i++;
		}
		else
		{
			pdest[n - 1] = psrc[n - 1];
			n--;
		}
	}
	return (dest);
}
