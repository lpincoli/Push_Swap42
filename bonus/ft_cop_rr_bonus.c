/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cop_rr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:26 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:27 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

t_list	*crrotirot_a(t_list *lst_a)
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
	}
	return (lst_a);
}

t_list	*crrotirot_b(t_list *lst_b)
{
	t_list	*tmp;

	tmp = lst_b;
	if (lst_b)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(&lst_b, tmp->next);
		tmp->next = NULL;
	}
	return (lst_b);
}

void	crrotirot_r(t_list **lst_a, t_list **lst_b)
{
	*lst_a = crrotirot_a((*lst_a));
	*lst_b = crrotirot_b((*lst_b));
}
