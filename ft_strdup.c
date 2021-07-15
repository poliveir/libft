/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:17:56 by poliveir          #+#    #+#             */
/*   Updated: 2021/03/08 17:37:51 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (!ptr)
		return (NULL);
	else
		ft_strcpy(ptr, s1);
	return (ptr);
}
