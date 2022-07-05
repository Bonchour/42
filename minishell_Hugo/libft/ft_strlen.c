/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <amorel@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:37:32 by amorel            #+#    #+#             */
/*   Updated: 2022/06/27 22:12:26 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int		l;
	char	*str;

	if (!s || !s[0])
		return (0);
	str = (char *)s;
	l = 0;
	while (str[l])
		l++;
	return (l);
}
