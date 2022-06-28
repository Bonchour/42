/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:13:35 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/13 12:44:49 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int k)
{
	char	*tab;
	size_t	i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
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
	return (tab);
}

char	*ft_read(int fd)
{
	char	*tab;
	int		cpt;
	ssize_t	c;
	char	*tab2;
	int		i;

	i = 0;
	tab2 = "";
	cpt = 0;
	tab = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	while (cpt != 1)
	{
		c = read(fd, tab, (BUFFER_SIZE));
		if (c < 0)
			return (NULL);
		if (c != 0)
			tab2 = ft_strjoin(tab2, tab, c);
//		free(tab);
		while (tab2[i])
		{
			if (tab[i] == '\n')
				cpt = 1;
			i++;
		}
		i = 0;
	}
	free(tab);
	return (tab2);
}
char	*ft_line(char *content, int cpt)
{
	int		i;
	int		j;
	int		k;
	char	*tab;

	j = 1;
	i = 0;
	while (j != cpt)
		{
			while (content[k] != '\n' && content[k])
				k++;
			k++;
			j++;
		}
	j = 0;
	while (content[k] != '\n' && content[k])
	{
		i++;
		k++;
	}
	tab = malloc(sizeof(char) * i + 1);
	i = 0;
	while(content[i] != '\n' && content[i])
	{
		tab[j] = content[i];
		i++;
		j++;
	}
	if (content[i] == '\n')
		tab[j] = '\n';
	else
		tab[j] = '\0';
	return (tab);
}
char	*ft_free(char **content, int cpt)
{
	int j;
	int	i;

	i = 0;
	j = 0;
	while (j != cpt)
	{
		while (content [i + 1][0] != '\n' && content[i + 1][0])
		{
			free(content[i]);
			i++;
		}
		j++;
	}
}


char	*get_next_line(int fd)
{
	static char *content;
	static int 	cpt;

	cpt++;
	if (cpt == 1)
		content = ft_read(fd);
	else
	{
		content = ft_free((char **)content, cpt);
		content = ft_read(fd);
	}
	return(ft_line(content, cpt));
}

int	main()
{
	int	file;
	char	*tab;
	char	*tab2;

	file = open("a", O_RDONLY);
	tab = get_next_line(file);
	printf("%s", tab);
	tab2 = get_next_line(file);
	printf("%s", tab2);
	tab = (get_next_line(file));
	printf("%s", tab);
	return (0);
}
