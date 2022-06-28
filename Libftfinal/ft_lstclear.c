/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:26:33 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/08 09:43:31 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = save;
	}
}
