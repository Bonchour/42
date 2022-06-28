/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_entier_dix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:50:49 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 10:08:13 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_entierndix(t_print *tab)
{
	int	decimal;

	decimal = va_arg(tab->args, int);
	ft_putnbr_fd(decimal, tab);
}
