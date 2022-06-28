/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:30:09 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 12:25:07 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

void	ft_printcharac(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->tl += write(1, &a, 1);
}

void	ft_putchar_fd(char c, t_print *tab)
{
	tab->tl += write(1, &c, 1);
}
