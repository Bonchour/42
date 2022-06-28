/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:06:30 by hde-min           #+#    #+#             */
/*   Updated: 2022/03/31 11:38:22 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	cpt;

	cpt = 0;
	i = 0;
	while (src[cpt])
		cpt++;
	if (size == 0)
		return (cpt);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dst[i] = '\0';
	}
	while (src[cpt])
		cpt++;
	return (cpt);
}
