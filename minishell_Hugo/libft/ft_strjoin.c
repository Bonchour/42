/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:59:36 by amorel            #+#    #+#             */
/*   Updated: 2022/07/01 00:01:50 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(s1) + ft_strlen(s2))
		str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i - ft_strlen(s1) < ft_strlen(s2))
	{
		str[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoinchr(char *s1, char s2)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc((ft_strlen(s1) + 2), sizeof(char));
	if (!str)
		return (s1);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s2;
	i++;
	str[i] = 0;
	free(s1);
	return (str);
}
