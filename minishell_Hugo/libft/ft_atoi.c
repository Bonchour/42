/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:19:22 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 20:16:06 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

static int	ft_overflow(int n)
{
	if (n == 1)
		return (-1);
	else
		return (0);
}

static bool	is_operator(char c)
{
	return (is_in_string(c, "+-"));
}

static bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	unsigned long long		result;
	int						minus;
	int						i;

	result = 0;
	minus = 1;
	i = 0;
	while (is_in_string((str[i]), "\t\n\v\f\r "))
		i++;
	if (is_operator(str[i]))
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (is_number(str[i]) && str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (i > 19 || result >= 9223372036854775808ULL)
		return (ft_overflow(minus));
	return (result * minus);
}
