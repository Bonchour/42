/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:04:37 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/06 09:58:30 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*tab;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s, ft_strlen(s) + 1);
	while (tab[i])
	{
		tab[i] = (*f)(i, tab[i]);
		i++;
	}
	return (tab);
}
