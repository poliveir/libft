/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:55:21 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/02 20:47:45 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(long long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = (char *)malloc(ft_count_digits(n) + 1);
	if (!str)
		return (NULL);
	i = ft_count_digits(n);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[i--] = '\0';
	while (nbr > 9)
	{
		str[i--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	str[i] = nbr + '0';
	return (str);
}
