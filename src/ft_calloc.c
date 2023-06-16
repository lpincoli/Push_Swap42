/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:31:09 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/06 15:54:29 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	count;
	void	*p;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	count = nmemb * size;
	p = malloc(count);
	if (p == NULL)
		return (NULL);
	else
		ft_bzero(p, count);
	return (p);
}
