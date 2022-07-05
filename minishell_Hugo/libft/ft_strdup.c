/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:32:11 by amorel            #+#    #+#             */
/*   Updated: 2022/06/29 14:11:24 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	l;

	l = 0;
	dest = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (dest != NULL)
	{
		while (s[l])
		{
			dest[l] = s[l];
			l++;
		}
		return (dest);
	}
	else
	{
		return (NULL);
	}
}
