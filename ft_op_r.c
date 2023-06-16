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

t_list	*rotate_a(t_list *lst_a, int r)
{
	t_list	*tmp;

	tmp = lst_a->next;
	if (lst_a)
	{
		ft_lstadd_back(&tmp, lst_a);
		lst_a->next = NULL;
		lst_a = tmp;
		if (r)
			return (lst_a);
		else
			ft_printf("ra\n");
	}
	return (lst_a);
}

t_list	*rotate_b(t_list *lst_b, int r)
{
	t_list	*tmp;

	tmp = lst_b->next;
	if (lst_b)
	{
		ft_lstadd_back(&tmp, lst_b);
		lst_b->next = NULL;
		lst_b = tmp;
		if (r)
			return (lst_b);
		ft_printf("rb\n");
	}
	return (lst_b);
}

void	rotate_r(t_list **lst_a, t_list **lst_b)
{
	*lst_a = rotate_a((*lst_a), 1);
	*lst_b = rotate_b((*lst_b), 1);
	ft_printf("rr\n");
}
