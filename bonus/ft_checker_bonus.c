/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:51:54 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:51:56 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

int	ft_is_thanos(t_list **a)
{
	t_list	*beholder;

	beholder = (*a);
	while (beholder->next)
	{
		if (beholder->content > beholder->next->content)
			return (0);
		beholder = beholder->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	lst_a = NULL;
	lst_b = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	if (check_args(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (i < ac)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(av[i]));
		lst_a->chunk = 0;
		lst_a->max = -1;
		i++;
	}
	if (ft_read_and_do(&lst_a, &lst_b))
		write(2, "Error\n", 6);
}
