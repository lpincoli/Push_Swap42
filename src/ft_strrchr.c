/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:58:39 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/07 16:34:10 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len;

	ptr = (char *)s;
	len = ft_strlen(s);
	while (*ptr != '\0')
		ptr++;
	if (*ptr == c)
		return (ptr);
	else
		ptr--;
	while (len > 0)
	{
		if (*ptr == c)
			return (ptr);
		len--;
		ptr--;
	}
	return (0);
}
