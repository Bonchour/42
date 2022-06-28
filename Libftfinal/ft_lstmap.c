/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:00 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/08 10:07:08 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*lst2;
	t_list	*lstnew;

	if (!lst)
		return (NULL);
	lst2 = lst;
	lstnew = ft_lstnew((*f)(lst2->content));
	if (!lstnew)
		return (NULL);
	lst2 = lst2->next;
	if (!lst2)
		return (NULL);
	while (lst2)
	{
		i = ft_lstnew((*f)(lst2->content));
		if (!i)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, i);
		lst2 = lst2 ->next;
	}
	return (lstnew);
}
