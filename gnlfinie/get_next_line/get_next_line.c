/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:51:32 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/13 10:08:58 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*content;
	char		*truecontent;
	int			i;
	static int	cpt;

	i = 0;
	cpt = ft_cpt(cpt);
	if (cpt == 1)
	{
		content = ft_read(fd);
		truecontent = malloc(sizeof(char) * ft_strlen((const char *) content));
	}
	if (cpt > 1)
	{
		free(truecontent);
		truecontent = malloc(sizeof(char) * ft_strlen((const char *) content));
		i = ft_skip_line(cpt, content);
	}
	ft_truereturn(i, content, truecontent);
	if (truecontent[0] == '\0')
		return (NULL);
	return (truecontent);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*char	*free_tab(char *tab, ssize_t cpt)
{
	int i;

	i = 0;
	while (i != cpt)
	{
		free(tab);
		i++;
	}
	free(tab);
}*/

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
//	ssize_t		c;
