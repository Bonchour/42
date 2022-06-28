/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:54:03 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 14:57:44 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbr_print(unsigned int i, t_print *tab, int ver)
{
	char	*str;
	char	*str2;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_nbr_print(i / 16, tab, ver);
		ft_nbr_print(i % 16, tab, ver);
	}
	else
	{
		if (ver == 1)
			tab->tl += write(1, &str[i], 1);
		else
			tab->tl += write(1, &str2[i], 1);
	}
}

void	ft_hexamin(t_print *tab)
{
	unsigned int	j;

	j = va_arg(tab->args, unsigned int);
	ft_nbr_print(j, tab, 1);
}
