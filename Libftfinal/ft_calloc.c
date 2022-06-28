/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:11 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/08 09:38:17 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	tab = malloc((size) * nmemb);
	if (!tab || nmemb * size > 2147483647)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
