/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:44:38 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 14:58:26 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstring(t_print *tab)
{
	char	*string;
	int		j;

	j = 0;
	string = va_arg(tab->args, char *);
	if (string == NULL)
	{
		write(1, "(null)", 6);
		tab->tl += +6;
	}
	else
	{
		while (string[j])
		{
			tab->tl += write(1, &string[j], 1);
			j++;
		}
	}
}
