/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:31:55 by amorel            #+#    #+#             */
/*   Updated: 2022/04/05 23:55:44 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*liste;

	liste = *lst;
	while (liste)
	{
		liste = (*lst)->next;
		(*del)((*lst)->content);
		free ((*lst));
		(*lst) = liste;
	}
}
