/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:02:48 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 14:02:54 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

static	t_list	*ft_topmin_b(t_list **lst_a, t_list **lst_b, int n, int *rot)
{
	if (n == 0)
	{
		if (*rot && (*lst_a)->chunk == (*lst_b)->chunk)
		{
			(*lst_a) = rotate_a(*lst_a, 0);
			if ((*lst_a)->max != 0)
				*rot = 0;
		}
	}
	while (n > 0)
	{
		if (*rot && (*lst_a)->chunk == (*lst_b)->chunk)
		{
			rotate_r(lst_a, lst_b);
			if ((*lst_a)->max != 0)
				*rot = 0;
		}
		else
			*lst_b = rotate_b(*lst_b, 0);
		n--;
	}
	return (*lst_b);
}

static	t_list	*ft_botmin_b(t_list *lst_b, int n)
{
	while (n > 0)
	{
		lst_b = rrotirot_b(lst_b, 0);
		n--;
	}
	return (lst_b);
}

static	t_min_max	ft_rel_pos(t_min_max var, int size)
{
	if (var.pos <= (size / 2) + 1)
	{
		var.top = 1;
		var.pos--;
	}
	else
	{
		var.top = 0;
		var.pos = (size - var.pos) + 1;
	}
	return (var);
}

t_list	*ft_move_closer(t_list **a, t_list **b, t_min_max minmax, int *rot)
{	
	int	c_a;
	int	c_b;

	c_a = (*a)->chunk;
	c_b = (*b)->chunk;
	if (minmax.top)
		*b = ft_topmin_b(a, b, (minmax.pos), rot);
	else
	{
		if (*rot == 1 && (c_a == c_b || c_a == (ft_lstlast(*b)->chunk)))
			(*a) = rotate_a(*a, 0);
		*b = ft_botmin_b(*b, minmax.pos);
	}
	return (*b);
}

t_list	*ft_find_closer(t_list **a, t_list **b, int chunk, int *rot)
{
	t_min_max	max;
	t_min_max	min;
	int			size;

	if (!b || b == NULL)
		return (NULL);
	max = ft_find_max(*b, chunk);
	min = ft_find_min(*b, chunk);
	size = ft_lstsize(*b);
	max = ft_rel_pos(max, size);
	min = ft_rel_pos(min, size);
	if (min.pos < max.pos)
	{
		*b = ft_move_closer(a, b, min, rot);
		(*b)->max = 0;
	}
	else
	{
		*b = ft_move_closer(a, b, max, rot);
		(*b)->max = 1;
	}
	return (*b);
}
