/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eldritch_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:02:48 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 14:02:54 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

int	ft_is_thanos(t_list **a)
{
	t_list	*beholder;

	beholder = (*a);
	while (beholder->next)
	{
		if (beholder->content > beholder->next->content)
			return (0);
		beholder = beholder->next;
	}
	return (1);
}

static	void	ft_sort_2(t_list **a)
{
	t_list	*beholder;
	t_list	*beholder2;

	beholder = (*a);
	beholder2 = beholder->next;
	if (beholder->content > beholder2->content)
		swap_a((*a), 0);
}

static	void	ft_sort_3(t_list **a)
{
	t_list	*beholder;

	beholder = (*a);
	if (beholder->content < beholder->next->content)
	{
		if (beholder->next->content > beholder->next->next->content)
		{
			(*a) = rrotirot_a((*a), 0);
			if (!ft_is_thanos(a))
				swap_a((*a), 0);
		}
	}
	else if (beholder->next->content < beholder->next->next->content)
	{
		if (beholder->next->next->content < beholder->content)
			(*a) = rotate_a((*a), 0);
		else
			swap_a((*a), 0);
	}
	else
	{
		swap_a((*a), 0);
		(*a) = rrotirot_a((*a), 0);
	}
}

static	void	ft_sort_little(t_list **a)
{
	int	num;

	num = ft_lstsize(*a);
	if (num == 2)
		ft_sort_2(a);
	else if (num == 3)
	{
		if (!ft_is_thanos(a))
			ft_sort_3(a);
	}
}

void	ft_eldritch_sort(t_list **a, t_list **b, int num)
{
	int		k;
	int		rot;
	t_list	*tmp;

	k = 1;
	rot = 0;
	while (num > 3)
	{
		ft_barbarian_chunk(a, b, num, k);
		k += 1;
		if (num % 4 == 0)
			num = (num / 4) * 3;
		else
			num = ((num / 4) * 3) + (num % 4);
	}
	ft_sort_little(a);
	ft_divetimp(a, b, &rot);
	tmp = ft_lstlast((*a));
	while (tmp->content < (*a)->content)
	{
		(*a) = rrotirot_a(*a, 0);
		tmp = ft_lstlast((*a));
	}
}
