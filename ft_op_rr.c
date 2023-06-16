/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:51:35 by rfrangin          #+#    #+#             */
/*   Updated: 2022/11/22 15:51:38 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

t_list	*rrotirot_a(t_list *lst_a, int r)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = lst_a->next;
	tmp2 = ft_lstlast(lst_a);
	if (lst_a)
	{
		while (tmp->next != tmp2)
			tmp = tmp->next;
		ft_lstadd_front(&lst_a, tmp2);
		tmp->next = NULL;
		if (r)
			return (lst_a);
		ft_printf("rra\n");
	}
	return (lst_a);
}

t_list	*rrotirot_b(t_list *lst_b, int r)
{
	t_list	*tmp;

	tmp = lst_b;
	if (lst_b)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(&lst_b, tmp->next);
		tmp->next = NULL;
		if (r)
			return (lst_b);
		ft_printf("rrb\n");
	}
	return (lst_b);
}

void	rrotirot_r(t_list **lst_a, t_list **lst_b)
{
	*lst_a = rrotirot_a((*lst_a), 1);
	*lst_b = rrotirot_b((*lst_b), 1);
	ft_printf("rrr\n");
}
