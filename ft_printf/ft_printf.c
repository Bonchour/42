/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-min <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:47:29 by hde-min           #+#    #+#             */
/*   Updated: 2022/04/22 15:13:14 by hde-min          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static t_print	*ft_initialise_tab(t_print *tab)
{
	tab->tl = 0;
	return (tab);
}

static int	ft_eval_str(t_print *tab, const char *str, int i)
{
	if (str[i] == 'c')
		ft_printcharac(tab);
	if (str[i] == 's')
		ft_printstring(tab);
	if (str[i] == 'p')
		ft_printpthexa(tab);
	if (str[i] == 'd')
		ft_printdeci(tab);
	if (str[i] == 'i')
		ft_entierndix(tab);
	if (str[i] == 'u')
		ft_desimalunsigned(tab);
	if (str[i] == 'x')
		ft_hexamin(tab);
	if (str[i] == 'X')
		ft_hexamax(tab);
	if (str[i] == '%')
		ft_pourcent(tab);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	t_print	*tab;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i = ft_eval_str(tab, str, i + 1);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	return (ret);
}
