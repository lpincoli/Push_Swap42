/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cop_s_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:36 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:38 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

void	cswap_a(t_list *lst)
{
	int	swap;

	if (lst || lst->next != NULL)
	{
		swap = lst->content;
		lst->content = lst->next->content;
		lst->next->content = swap;
	}
}

void	cswap_b(t_list *lst)
{
	int	swap;

	if (lst || lst->next != NULL)
	{
		swap = lst->content;
		lst->content = lst->next->content;
		lst->next->content = swap;
	}
}

void	cswap_s(t_list *lst_a, t_list *lst_b)
{
	cswap_a(lst_a);
	cswap_b(lst_b);
}
