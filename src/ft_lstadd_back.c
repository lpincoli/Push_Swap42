/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:13:59 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/08 01:30:41 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
		{	
			*lst = nw;
		}
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = nw;
		}
	}
}
