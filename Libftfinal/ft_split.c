/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:29:42 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/20 10:52:03 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

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

static void	ft_free(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = -1;
	tab = malloc((ft_linenumber(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (tab = ft_calloc(sizeof(char), 1));
	while (++j < ft_linenumber(s, c))
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_substr(s, i, ft_strilen(s, c, i));
		tab[j][ft_strilen(s, c, i)] = 0;
		if (!tab[j])
		{
			ft_free(tab, j);
			return (tab = ft_calloc(sizeof(char), 1));
		}
		i += ft_strilen(s, c, i);
	}
	tab[j] = NULL;
	return (tab);
}
