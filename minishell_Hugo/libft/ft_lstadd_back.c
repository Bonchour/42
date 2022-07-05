/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:12:00 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 00:00:15 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*liste;

	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			liste = ft_lstlast(*lst);
			liste->next = new;
		}
	}
}
