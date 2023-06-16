/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:26:54 by rfrangin          #+#    #+#             */
/*   Updated: 2022/11/09 15:26:57 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line_bonus.h"

char	*ft_substr(const char *src, unsigned int fst, size_t len)
{
	size_t	i;
	size_t	k;
	char	*str;

	str = (char *)malloc(sizeof(*src) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	k = 0;
	while (src[i])
	{
		if (i >= fst && k < len)
		{
			str[k] = src[i];
			k++;
		}
		i++;
	}
	str[k] = 0;
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(src);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int i)
{
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	if (i == '\0')
		return ((char *)str);
	return (0);
}
