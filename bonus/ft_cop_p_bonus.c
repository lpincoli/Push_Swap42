/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cop_p_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:05 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:07 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

void	cpush_a(t_list **lst_b, t_list **lst_a)
{
	t_list	*tmp;

	if (lst_b)
	{
		tmp = (*lst_b)->next;
		ft_lstadd_front(lst_a, *lst_b);
		*lst_b = tmp;
	}
}

void	cpush_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	if (lst_a)
	{
		tmp = (*lst_a)->next;
		ft_lstadd_front(lst_b, *lst_a);
		*lst_a = tmp;
	}
}
