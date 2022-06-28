/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:05:07 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/07 15:22:54 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*cpy_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	cpy_src = (unsigned char *) src;
	cpy = (unsigned char *) dest;
	if (dest > src)
	{
		while (n -- > 0)
		{
			cpy[n] = cpy_src[n];
		}
	}
	else
	{
		while (i != n)
		{
			cpy[i] = cpy_src[i];
			i++;
		}
	}
	return (dest);
}
