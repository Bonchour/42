/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:15:55 by hde-min           #+#    #+#             */
/*   Updated: 2022/06/08 13:22:22 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_putchar(char i)
{
	if (!write(1, &i, 1))
		return ;
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		if (!write(1, "-2147483648", 11))
			return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		if (!write(1, "-", 1))
			return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
