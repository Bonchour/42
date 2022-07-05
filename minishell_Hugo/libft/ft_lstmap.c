/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:48:38 by amorel            #+#    #+#             */
/*   Updated: 2022/04/05 23:58:38 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*templist;
	t_list	*newlist;
	t_list	*begin;

	if (lst)
	{
		templist = lst;
		begin = ft_lstnew((*f)(templist->content));
		if (!begin)
			return (NULL);
		templist = templist->next;
		while (templist)
		{
			newlist = ft_lstnew((*f)(templist->content));
			if (!newlist)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			ft_lstadd_back(&begin, newlist);
			templist = templist->next;
		}
		return (begin);
	}
	return (NULL);
}
