/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorel <Marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:00:28 by amorel            #+#    #+#             */
/*   Updated: 2022/04/06 23:01:42 by amorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(long long n)
{
	int	negative;
	int	i;

	i = 0;
	negative = 0;
	if (n == -2147483648)
		return (11);
	if (n * -1 > n)
	{
		negative = 1;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i + negative);
}

static void	ft_putnbr(char *str, long long nb, int i, int len)
{
	if (nb == -2147483648)
	{
		str[len] = '8';
		len--;
		ft_putnbr(str, nb / 10, i, len);
	}
	else
	{
		if (nb > 9 && len > i)
			ft_putnbr(str, nb / 10, i, len - 1);
		str[len - 1 + i] = (48 + nb % 10);
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			minus;
	long long	nbr;

	nbr = n;
	i = 0;
	minus = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
		minus = 1;
		str = malloc((ft_ilen(nbr) + 1 + minus) * sizeof(char));
		if (!str)
			return (str = ft_calloc(sizeof(char), 1));
		str[0] = '-';
	}
	else
		str = malloc((ft_ilen(nbr) + 1 + minus) * sizeof(char));
	if (!str)
		return (str = ft_calloc(sizeof(char), 1));
	ft_putnbr(str, nbr, i, ft_ilen(nbr));
	str[ft_ilen(nbr) + minus] = 0;
	return (str);
}
