/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:03:52 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/01 09:47:01 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*l;
	char	*b;
	size_t	j;
	size_t	i;

	i = 0;
	l = (char *)little;
	b = (char *)big;
	if (l[0] == '\0')
		return (b);
	while (b[i] != '\0')
	{
		j = 0;
		while (i + j < len && b[i + j] == l[j])
		{
			if (l[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		i++;
	}
	return (0);
}
