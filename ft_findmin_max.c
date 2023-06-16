/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmin_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:13:44 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/08 17:13:48 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

t_min_max	ft_first_min(t_list *lst, int chunk)
{
	t_list		*lbehold;
	t_min_max	min;

	lbehold = ft_lstlast(lst);
	if (lst->chunk == chunk)
	{
		min.value = lst->content;
		min.pos = 1;
	}
	else
	{
		min.value = lbehold->content;
		min.pos = ft_lstsize(lst);
	}
	return (min);
}

t_min_max	ft_find_min(t_list *lst, int chunk)
{
	t_list		*beholder;
	t_min_max	min;
	int			i;

	i = 1;
	min = ft_first_min(lst, chunk);
	beholder = lst;
	while (beholder)
	{
		if (beholder->chunk == chunk)
		{
			if (beholder->content < min.value)
			{
				min.pos = i;
				min.value = beholder->content;
			}
		}
		beholder = beholder->next;
		i++;
	}
	min.top = 1;
	return (min);
}

t_min_max	ft_find_max(t_list *lst, int chunk)
{
	t_list		*beholder;
	t_min_max	max;
	int			i;

	i = 1;
	beholder = lst;
	max.value = beholder->content;
	max.pos = 1;
	while (beholder)
	{
		if (beholder->chunk == chunk)
		{
			if (beholder->content > max.value)
			{
				max.value = beholder->content;
				max.pos = i;
			}
		}
		beholder = beholder->next;
		i++;
	}
	max.top = 1;
	return (max);
}
