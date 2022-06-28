/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:25:34 by hde-min           #+#    #+#             */
/*   Updated: 2022/03/31 13:08:45 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t lenght)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while (f[i] && s[i] && (first[i] == s[i]) && (i < lenght - 1))
	{
		i++;
	}
	if (lenght == 0)
		return (0);
	if (f[i] - s[i] > 0)
		return (1);
	else if (f[i] - s[i] < 0)
		return (-1);
	else if (f[i] - s[i] == 0 || lenght == 0)
		return (0);
	else
		return (0);
}
