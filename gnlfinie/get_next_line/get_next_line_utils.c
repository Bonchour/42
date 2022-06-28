/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:27:42 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/13 11:28:23 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2, int k)
{
	char 	*tab;
	size_t	i;
	int		j;
	char	*tab2;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	tab2 = s1;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1++;
		i++;
	}
	while (*s2 && j != k)
	{
		tab[i] = *s2++;
		i++;
		j++;
	}
	tab[i] = '\0';
//	free(tab2);
	return (tab);
}



int ft_cpt(int cpt)
{
	cpt = cpt + 1;
	return (cpt);
}

int	ft_skip_line(int cpt, char *content)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (j != cpt)
	{
		while (content[i] != '\n')
			i++;
		i++;
		j++;
	}
	return (i);
}

void	ft_truereturn(int i, char *content, char *truecontent)
{
	int	j;

	j = 0;
	while (content[i] != '\n' && content[i] != '\0')
	{
		truecontent[j] = content[i];
		i++;
		j++;
	}
	if (content[i] == '\0')
		truecontent[j] = '\0';
	else
		truecontent[j] = '\n';
}

char	*ft_read(int fd)
{
	char	*tab;
	char	*tab2;
	int		cpt;
	ssize_t	c;
	int		i;

	cpt = 0;
	tab2 = "";
	while (cpt  != 1)
	{
		tab = malloc(sizeof(char *) * BUFFER_SIZE + 1);
		c = read(fd, tab, (BUFFER_SIZE));
		if (c < 0)
			return (NULL);
		if (c != 0)
		{
			tab2 = ft_strjoin(tab2, tab, cpt);
		}
		free (tab);
		while (tab[i])
		{
			if (tab[i] == '\n')
				cpt = 1;
			i++;
		}
		i = 0;
	}
	return (tab2);
}
