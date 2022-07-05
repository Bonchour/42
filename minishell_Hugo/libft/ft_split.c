/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:25 by amorel            #+#    #+#             */
/*   Updated: 2022/07/03 21:40:45 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_linenumber(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

static int	ft_strilen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **strmatrix, int j)
{
	while (j-- > 0)
		free(strmatrix[j]);
	free(strmatrix);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**strmatrix;

	i = 0;
	j = -1;
	strmatrix = malloc((ft_linenumber(s, c) + 1) * sizeof(char *));
	if (!strmatrix)
		return (strmatrix = ft_calloc(sizeof(char), 1));
	while (++j < ft_linenumber(s, c))
	{
		while (s[i] == c)
			i++;
		strmatrix[j] = ft_substr(s, i, ft_strilen(s, c, i));
		strmatrix[j][ft_strilen(s, c, i)] = 0;
		if (!strmatrix[j])
		{
			ft_free(strmatrix, j);
			return (strmatrix = ft_calloc(sizeof(char), 1));
		}
		i += ft_strilen(s, c, i);
	}
	strmatrix[j] = NULL;
	return (strmatrix);
}
