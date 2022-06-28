/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_deci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:49:01 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 12:27:20 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, t_print *tab)
{
	if (n < -2147483647)
	{
		tab->tl += write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', tab);
		ft_putnbr_fd(n * (-1), tab);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, tab);
		ft_putnbr_fd(n % 10, tab);
	}
	else
	{
		ft_putchar_fd(n + 48, tab);
	}
}

void	ft_printdeci(t_print *tab)
{
	int	decimal;

	decimal = va_arg(tab->args, int);
	ft_putnbr_fd(decimal, tab);
}
