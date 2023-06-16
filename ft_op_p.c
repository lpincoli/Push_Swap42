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

void	push_a(t_list **lst_b, t_list **lst_a)
{
	t_list	*tmp;

	if (lst_b)
	{
		tmp = (*lst_b)->next;
		ft_lstadd_front(lst_a, *lst_b);
		*lst_b = tmp;
		ft_printf("pa\n");
	}
}

void	push_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (lst_a)
	{
		tmp = (*lst_a)->next;
		ft_lstadd_front(lst_b, *lst_a);
		*lst_a = tmp;
		ft_printf("pb\n");
	}
}
