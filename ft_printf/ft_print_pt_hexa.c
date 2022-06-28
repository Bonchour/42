/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pt_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:47:14 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 13:14:16 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpthexa(t_print *tab)
{
	unsigned long long	i;

	i = va_arg(tab->args, unsigned long long);
	if (i == 0)
	{
		write(1, "(nil)", 5);
		tab->tl += 5;
	}
	else
	{
		write(1, "0x", 2);
		tab->tl += 2;
		ft_nbrprint(i, tab);
	}
}

void	ft_nbrprint(unsigned long long i, t_print *tab)
{
	char	*str;

	str = "0123456789abcdef";
	if (i >= 16)
	{
		ft_nbrprint(i / 16, tab);
		ft_nbrprint(i % 16, tab);
	}
	else
		tab->tl += write(1, &str[i], 1);
}
