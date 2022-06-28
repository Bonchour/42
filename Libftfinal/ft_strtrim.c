/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:35:55 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/04 14:01:54 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isnotallowed(char c, char const *set)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			cpt++;
		i++;
	}
	return (cpt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*str;

	j = ft_strlen(s1) - 1;
	i = 0;
	while (ft_isnotallowed(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	while (ft_isnotallowed(s1[j], set))
		j--;
	return (ft_substr(s1, i, (j) - i + 1));
}
