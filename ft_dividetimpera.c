/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dividetimpera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:17:25 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/23 16:17:27 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

static	void	ft_change_chunk(t_list **a, t_list **b)
{
	t_list	*beholder;
	t_list	*tmp;

	beholder = ft_lstlast(*b);
	if (((*b)->chunk != (*a)->chunk))
	{
		if (beholder->chunk != (*a)->chunk)
		{
			tmp = ft_lstlast((*a));
			while (tmp->content < (*a)->content)
			{
				(*a) = rrotirot_a(*a, 0);
				tmp = ft_lstlast((*a));
			}
		}
	}
}

static	void	ft_sistema_a(t_list **a, t_list **b, int *rot)
{
	t_list	*tmp;

	tmp = (*a);
	if (!(*b) || !b)
		return ;
	ft_change_chunk(a, b);
	if (tmp->max)
	{
		*rot = 0;
		return ;
	}
	else
		*rot = 1;
}

t_list	*ft_bellum(t_list **a, t_list **b, int *rot, int chunk)
{
	while ((*b)->chunk == chunk)
	{
		(*b) = ft_find_closer(a, b, chunk, rot);
		push_a(b, a);
		ft_sistema_a(a, b, rot);
		if (!(*b))
			return (NULL);
	}
	return (*b);
}

void	ft_divetimp(t_list **a, t_list **b, int *rot)
{
	int		chunk;
	t_list	*tmp;

	while (*b)
	{
		chunk = (*b)->chunk;
		(*b) = ft_bellum(a, b, rot, chunk);
		if (!(*b))
			return ;
		tmp = ft_lstlast(*b);
		while (tmp->chunk == chunk)
		{
			tmp = ft_lstlast(*b);
			if (tmp->chunk == chunk)
			{
				(*b) = ft_find_closer(a, b, chunk, rot);
				push_a(b, a);
				ft_sistema_a(a, b, rot);
			}
		}
	}
}
