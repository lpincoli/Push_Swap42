/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <lpincoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:56:32 by lpincoli          #+#    #+#             */
/*   Updated: 2023/06/16 16:13:23 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"


void ft_clear_list(t_list *lst)
{
	t_list *tmp;
	
	tmp = lst;
	while (tmp)
	{
		lst = lst->next;
		free(tmp);
		tmp = lst;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;
	int		num;

	i = 0;
	lst_a = NULL;
	lst_b = NULL;
	if (ac < 2)
		return (0);
	if (check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (++i < ac)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(av[i]));
		lst_a->chunk = 0;
		lst_a->max = -1;
	}
	if (ft_is_thanos(&lst_a))
		return (0);
	num = (ac - 1);
	ft_eldritch_sort(&lst_a, &lst_b, num);
	ft_clear_list(lst_a);
	ft_clear_list(lst_b);
}
