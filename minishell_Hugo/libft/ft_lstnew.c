/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:34:19 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 22:24:02 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = (t_list *)malloc(sizeof(t_list));
	if (!liste)
		return (liste = ft_calloc(sizeof(t_list), 1));
	liste->next = NULL;
	liste->content = content;
	return (liste);
}
