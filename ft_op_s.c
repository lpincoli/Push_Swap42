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

void	swap_a(t_list *lst, int s)
{
	int	swap;

	if (lst || lst->next != NULL)
	{
		swap = lst->content;
		lst->content = lst->next->content;
		lst->next->content = swap;
		if (s)
			return ;
		ft_printf("sa\n");
	}
}

void	swap_b(t_list *lst, int s)
{
	int	swap;

	if (lst || lst->next != NULL)
	{
		swap = lst->content;
		lst->content = lst->next->content;
		lst->next->content = swap;
		if (s)
			return ;
		ft_printf("sb\n");
	}
}

void	swap_s(t_list *lst_a, t_list *lst_b)
{
	swap_a(lst_a, 1);
	swap_b(lst_b, 1);
	ft_printf("ss\n");
}
