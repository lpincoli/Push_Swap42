/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:00:13 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 15:00:20 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_H
# define FT_PUSH_H
# include "ft_printf.h"
# include "ft_push_checker.h"

typedef struct minmax
{
	int	pos;
	int	value;
	int	top;
}	t_min_max;

void		ft_eldritch_sort(t_list **a, t_list **b, int num);
void		ft_divetimp(t_list **a, t_list **b, int *rot);
int			check_args(int ac, char **av);
void		swap_a(t_list *lst, int s);
void		swap_b(t_list *lst, int s);
void		swap_s(t_list *lst_a, t_list *lst_b);
void		push_a(t_list **lst_a, t_list **lst_b);
void		push_b(t_list **lst_b, t_list **lst_a);
t_list		*rotate_a(t_list *lst_a, int r);
t_list		*rotate_b(t_list *lst_b, int r);
void		rotate_r(t_list **lst_a, t_list **lst_b);
t_list		*rrotirot_a(t_list *lst_a, int r);
t_list		*rrotirot_b(t_list *lst_b, int r);
void		rrotirot_r(t_list **lst_a, t_list **lst_b);
t_min_max	ft_find_min(t_list *lst, int chunk);
t_min_max	ft_find_max(t_list *lst, int chunk);
void		ft_quicksort(int *arr, int size);
t_list		*ft_find_closer(t_list **a, t_list **b, int chunk, int *rot);
void		ft_barbarian_chunk(t_list **a, t_list **b, int num, int n_k);
int			ft_is_thanos(t_list **a);

#endif
