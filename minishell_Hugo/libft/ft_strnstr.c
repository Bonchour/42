/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:51:35 by amorel            #+#    #+#             */
/*   Updated: 2022/04/05 15:25:55 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fndstr(const char *base, char *key, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i <= len)
	{
		if (*key == '\0')
			return ((char *)(base - (key - little)));
		else if (*base == '\0')
			break ;
		if (*base == *key)
			key++;
		else
		{
			base -= (key - little);
			i -= (key - little);
			key = (char *) little;
		}
		base++;
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if (*little == '\0')
		return ((char *) big);
	return (fndstr(big, (char *) little, little, len));
}
