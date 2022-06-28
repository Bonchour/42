/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_desimal_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:52:26 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 14:56:30 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putnbr_2(unsigned int n, t_print *tab)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, tab);
		ft_putnbr_fd(n % 10, tab);
	}
	else
		ft_putchar_fd(n + 48, tab);
}

void	ft_desimalunsigned(t_print *tab)
{
	unsigned int	j;

	j = va_arg(tab->args, long long int);
	if (j > 4294967294)
		ft_putnbr_2(4294967295, tab);
	else
	{
		ft_putnbr_2(j, tab);
	}
}
