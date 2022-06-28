/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:59:24 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 15:15:03 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_print
{
	va_list			args;
	int				tl;
}	t_print;

void	ft_printcharac(t_print *tab);
void	ft_putchar_fd(char c, t_print *tab);
void	ft_putnbr_fd(int n, t_print *tab);
void	ft_putnbr_2(unsigned int n, t_print *tab);
void	ft_printstring(t_print *tab);
void	ft_printpthexa(t_print *tab);
void	ft_printdeci(t_print *tab);
void	ft_entierndix(t_print *tab);
void	ft_desimalunsigned(t_print *tab);
void	ft_hexamin(t_print *tab);
void	ft_hexamax(t_print *tab);
void	ft_pourcent(t_print *tab);
int		ft_printf(const char *str, ...);
void	ft_nbrprint(unsigned long long i, t_print *tab);
void	ft_nbr_print(unsigned int i, t_print *tab, int ver);
#endif
