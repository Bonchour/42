/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:21:34 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/08 09:44:54 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!(lst))
		return (NULL);
	while (lst != NULL)
	{
		if (last->next == NULL)
			return (last);
		else
			last = last->next;
	}
	return (last);
}
