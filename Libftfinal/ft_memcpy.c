/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:03:50 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/07 15:18:38 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cpy;
	const char	*cpy_src;

	if (!dest && !src)
		return (NULL);
	cpy_src = src;
	cpy = dest;
	while (n != 0)
	{
		*cpy = *cpy_src;
		cpy++;
		cpy_src++;
		n--;
	}
	return (dest);
}
