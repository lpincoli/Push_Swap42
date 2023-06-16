/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_do_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:52:45 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 17:52:46 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

int	ft_do_op(char *str, t_list **a, t_list **b)
{
	if (ft_strncmp(str, "sa\n", 4) == 0)
		cswap_a(*a);
	else if (ft_strncmp(str, "sb\n", 4) == 0)
		cswap_b(*b);
	else if (ft_strncmp(str, "ss\n", 4) == 0)
		cswap_s(*a, *b);
	else if (ft_strncmp(str, "pa\n", 4) == 0)
		cpush_a(b, a);
	else if (ft_strncmp(str, "pb\n", 4) == 0)
		cpush_b(a, b);
	else if (ft_strncmp(str, "ra\n", 4) == 0)
		(*a) = crotate_a(*a);
	else if (ft_strncmp(str, "rb\n", 4) == 0)
		(*b) = crotate_b(*b);
	else if (ft_strncmp(str, "rr\n", 4) == 0)
		crotate_r(a, b);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		(*a) = crrotirot_a(*a);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		(*b) = crrotirot_b(*b);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		crrotirot_r(a, b);
	else
		return (1);
	return (0);
}

int	ft_read_and_do(t_list **a, t_list **b)
{
	char	*str;

	str = calloc(3, sizeof(char));
	while (str)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, "exit\n", 5) == 0)
			break ;
		if (ft_do_op(str, a, b))
			return (1);
	}
	free(str);
	if (ft_is_thanos(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
