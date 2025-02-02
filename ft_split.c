/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:42:29 by poliveir          #+#    #+#             */
/*   Updated: 2021/02/25 16:23:26 by poliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t
	ft_find_char(char const s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static size_t
	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	n_s;

	i = 0;
	n_s = 0;
	while (s[i] != '\0')
	{
		if (ft_find_char(s[i + 1], c)
			&& !ft_find_char(s[i], c))
			n_s++;
		i++;
	}
	return (n_s);
}

static char
	*ft_clean(char const *s, size_t i, size_t n, char **ptr)
{
	size_t	m;
	char	*str;
	int		j;

	m = 0;
	str = (char *)malloc((i - n) + 1);
	if (!str)
	{
		while (ptr[m])
			free(ptr[m++]);
		free(ptr);
		return (NULL);
	}
	j = 0;
	while (n < i)
		str[j++] = s[n++];
	str[j] = '\0';
	return (str);
}

char
	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	n;
	size_t	m;

	i = 0;
	m = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc(8 * ((ft_count_str(s, c)) + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		n = i;
		while (ft_find_char(s[i], c) == 0)
			i++;
		if ((i - n) != 0)
			ptr[m++] = ft_clean(s, i, n, ptr);
		if (s[i] != '\0')
			i++;
	}
	ptr[m] = NULL;
	return (ptr);
}
