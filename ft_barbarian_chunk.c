/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_barbarian_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:02:48 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 14:02:54 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

static	int	*ft_list_to_array(t_list *a)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a;
	arr = malloc(ft_lstsize(a) * sizeof(int));
	while (tmp)
	{
		arr[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	return (arr);
}

static	int	ft_find_mid(t_list *lst)
{
	int	*arr;
	int	ret;

	arr = ft_list_to_array(lst);
	ft_quicksort(arr, ft_lstsize(lst));
	ret = arr[ft_lstsize(lst) / 4];
	free(arr);
	return (ret);
}

static	int	ft_findoublemid(t_list *lst)
{
	int	*arr;
	int	ret;

	arr = ft_list_to_array(lst);
	ft_quicksort(arr, ft_lstsize(lst));
	ret = arr[ft_lstsize(lst) / 8];
	free(arr);
	return (ret);
}

static	void	ft_checkborder(t_list **a, t_list **b, int mid, int doublemid)
{
	if (*b && (*b)->next)
	{
		if ((*b)->content < doublemid && (*b)->next)
		{
			if ((*a)->content >= mid)
				rotate_r(a, b);
			else
				(*b) = rotate_b((*b), 0);
		}
	}
}

void	ft_barbarian_chunk(t_list **a, t_list **b, int num, int n_k)
{
	int	mid;
	int	doublemid;
	int	count;

	mid = ft_find_mid(*a);
	doublemid = ft_findoublemid(*a);
	count = 0;
	if (num % 4 != 0)
	{
		count++;
		num += (4 - (num % 4));
	}
	while (count < (num / 4))
	{
		while ((*a)->content < mid)
		{
			(*a)->chunk = n_k;
			push_b(a, b);
			count++;
			ft_checkborder(a, b, mid, doublemid);
		}
		while ((*a)->content >= mid && count < (num / 4))
			(*a) = rotate_a((*a), 0);
	}
}
