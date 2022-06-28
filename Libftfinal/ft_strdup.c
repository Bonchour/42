/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:59:57 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/07 16:04:50 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		cpt;
	char	*str;

	cpt = ft_strlen(s);
	str = malloc(sizeof(char) * (cpt + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, cpt + 1);
	return (str);
}
