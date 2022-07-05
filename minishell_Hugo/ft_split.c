/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:25 by amorel            #+#    #+#             */
/*   Updated: 2022/06/29 19:04:54 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_linenumber(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	l;

	l = 0;
	k = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if ((k % 2 == 0 && l % 2 == 0) && (s[i] == c || s[i] == 0)
			&& (s[i + 1] != c && s[i + 1]))
		{
			j++;
		}
		if (s[i] == '\'')
			k++;
		if (s[i] == '"')
			l++;
		i++;
	}
	return (j + 1);
}

static int	ft_qouterspace(char const *s, int i)
{
	while (s[i])
	{
		if (s[i] == ' ')
			return (espace);
		else if (s[i] == '\'')
			return (simpleq);
		else if (s[i] == '"')
			return (doubleq);
		i++;
	}
	return (nothing);
}

static int	ft_strilen(char const *s, char c, int i)
{
	int	len;
	int	quote;
	int	j;

	len = 0;
	while (s[i])
	{
		quote = ft_qouterspace(s, i);
		j = 0;
		if (quote == espace || quote == nothing)
		{
			while (s[i] != c && s[i])
			{
				len++;
				i++;
			}
			return (len);
		}
		else if (quote == simpleq)
		{
			while (j < 2)
			{
				if (s[i] == '\'')
					j++;
				len++;
				i++;
			}
		}
		else if (quote == doubleq)
		{
			while (j < 2)
			{
				if (s[i] == '"')
					j++;
				len++;
				i++;
			}
		}
	}
	return (len);
}

char	*fuckdaquotes(char *str)
{
	int		i;
	int		quote;
	char	*streturn;

	streturn = ft_calloc(sizeof(char), 1);
	i = 0;
	while (str[i])
	{
		quote = ft_qouterspace(str, i);
		if (quote == espace)
		{
			while (str[i] != ' ')
			{
				streturn = ft_strjoinchr(streturn, str[i]);
				i++;
			}
			return (free(str), streturn);
		}
		else if (quote == simpleq)
		{
			while (str[i] != '\'')
			{
				if (str[i] == '\'')
					i++;
				streturn = ft_strjoinchr(streturn, str[i]);
				i++;
			}
			i++;
		}
		else if (quote == doubleq)
		{
			while (str[i] != '"')
			{
				if (str[i] == '"')
					i++;
				streturn = ft_strjoinchr(streturn, str[i]);
				i++;
			}
			i++;
		}
		else if (quote == nothing)
		{
			while (str[i])
			{
				streturn = ft_strjoinchr(streturn, str[i]);
				i++;
			}
			return (free(str), streturn);
		}
	}
	return (free(str), streturn);
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
		return (NULL);
	while (++j < ft_linenumber(s, c))
	{
		while (s[i] == c)
			i++;
		strmatrix[j] = ft_substr(s, i, ft_strilen(s, c, i));
		strmatrix[j] = fuckdaquotes(strmatrix[j]);
		if (!strmatrix[j])
		{
			ft_free(strmatrix, j);
			return (NULL);
		}
		i += ft_strilen(s, c, i);
	}
	strmatrix[j] = NULL;
	return (strmatrix);
}
