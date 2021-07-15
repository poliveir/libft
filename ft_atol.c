/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 19:29:19 by poliveir          #+#    #+#             */
/*   Updated: 2021/07/02 19:29:26 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	nbr;

	while (ft_iswspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (ft_isdigit(*str))
	{
		nbr = 0;
		while (ft_isdigit(*str))
			nbr = (nbr * 10) + (*str++ - '0');
		return (nbr * sign);
	}
	return (0);
}
