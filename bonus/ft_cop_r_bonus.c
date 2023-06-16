/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cop_r_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:20 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:22 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

t_list	*crotate_a(t_list *lst_a)
{
	t_list	*tmp;

	tmp = lst_a->next;
	if (lst_a)
	{
		ft_lstadd_back(&tmp, lst_a);
		lst_a->next = NULL;
		lst_a = tmp;
	}
	return (lst_a);
}

t_list	*crotate_b(t_list *lst_b)
{
	t_list	*tmp;

	tmp = lst_b->next;
	if (lst_b)
	{
		ft_lstadd_back(&tmp, lst_b);
		lst_b->next = NULL;
		lst_b = tmp;
	}
	return (lst_b);
}

void	crotate_r(t_list **lst_a, t_list **lst_b)
{
	*lst_a = crotate_a((*lst_a));
	*lst_b = crotate_b((*lst_b));
}
