/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:29:10 by amorel            #+#    #+#             */
/*   Updated: 2022/06/30 23:33:22 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcat(char *dst, const char *src, int size)
{
	char	*dest2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (dst)
	{
		dest2 = ft_calloc(ft_strlen(dst) + size + 1, 1);
		while (dst[i] != '\0')
		{
			dest2[i] = dst[i];
			i++;
		}
	}
	else
		dest2 = ft_calloc(2, 1);
	while (src[j] && j < size)
	{
		dest2[i + j] = src[j];
		j++;
	}
	dest2[i + j] = '\0';
	if (dst)
		free(dst);
	return (dest2);
}
