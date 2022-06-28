/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:51:32 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/12 10:46:35 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*content;
	char		*truecontent;
	ssize_t		c;
	int			i;
	static int	cpt;

	cpt = ft_cpt(cpt);
	if (cpt == 1)
	{
		truecontent = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		c = read(fd, content, (BUFFER_SIZE + 1));
		if (c < 0)
			return (NULL);
	}
	else if (cpt > 1)
	{
		free(truecontent);
		truecontent = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	i = ft_skip_line(cpt, content);
	ft_truereturn(i, content, truecontent);
	if (truecontent[0] == '\0')
		return (NULL);
	return ((char *)truecontent);
}

/*int	main()
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
}*/
