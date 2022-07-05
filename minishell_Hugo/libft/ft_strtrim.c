/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:13:07 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 22:17:19 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_in_string(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int long		i;
	int						j;
	int						size;
	char					*str;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_in_string(s1[i], set))
		i++;
	if (!s1 || !s1[i])
		return (str = ft_calloc(sizeof(char), 1));
	while (is_in_string(s1[j], set))
		j--;
	size = j - i;
	str = malloc((size + 2) * sizeof(char));
	if (!str)
		return (str = ft_calloc(sizeof(char), 1));
	j = -1;
	while (++j <= size)
		str[j] = s1[j + i];
	str[j] = 0;
	return (str);
}
