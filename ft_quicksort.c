/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:02:48 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 14:02:54 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

static	void	ft_swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

static	int	ft_partition(int *arr, int size)
{
	int	pivot;
	int	l;
	int	r;

	pivot = arr[0];
	l = 0;
	r = size;
	while (l < r)
	{
		while (arr[--r] > pivot && r > l)
			;
		if (r != l)
		{
			while (arr[++l] <= pivot && l < r)
				;
			ft_swap(arr, l, r);
		}
	}
	ft_swap(arr, l, 0);
	return (l + 1);
}

void	ft_quicksort(int *arr, int size)
{
	int	q;

	if (size > 0)
	{
		q = ft_partition(arr, size);
		ft_quicksort(arr, q - 1);
		ft_quicksort(&arr[q], size - q);
	}
}
