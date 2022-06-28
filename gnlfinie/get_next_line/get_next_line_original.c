/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:51:32 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/11 15:41:53 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

 int ft_cpt(int cpt)
{
	cpt++;
	return (cpt);
}

char *get_next_line(int fd)
{
	char		*content;
	char		*truecontent;
	ssize_t		c;
	int			i;
	int			j;
	static int	cpt;

	j = 1;
	i = 0;
	cpt = ft_cpt(cpt);
	if (cpt == 1)
	{
		truecontent = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		c = read(fd, content, (BUFFER_SIZE + 1));
		if (c < 0)
			return (NULL);
	}
	if (cpt > 1)
	{
		free(truecontent);
		truecontent = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	while (j != cpt)
	{
		while (content[i] != '\n')
			i++;
		i++;
		j++;
	}
	j = 0;
	if (content[i] == '\0')
			return (NULL);
	while (content[i] != '\n' && content[i] != '\0')
	{
		truecontent[j] = content[i];
		i++;
		j++;
	}
	if (content[i] == '\0')
		truecontent[j] = '\0';
	else
	{
		truecontent[j] = '\n';
	}
	return ((char *)truecontent);
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
