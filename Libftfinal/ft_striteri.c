/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:44:52 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/05 15:00:32 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
