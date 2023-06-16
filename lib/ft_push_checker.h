/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:18:11 by lpincoli          #+#    #+#             */
/*   Updated: 2022/12/10 14:18:13 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_CHECKER_H
# define FT_PUSH_CHECKER_H

int		ft_read_and_do(t_list **a, t_list **b);
int		ft_do_op(char *str, t_list **a, t_list **b);
void	cswap_a(t_list *lst);
void	cswap_b(t_list *lst);
void	cswap_s(t_list *lst_a, t_list *lst_b);
void	cpush_a(t_list **lst_b, t_list **lst_a);
void	cpush_b(t_list **lst_a, t_list **lst_b);
t_list	*crotate_a(t_list *lst_a);
t_list	*crotate_b(t_list *lst_b);
void	crotate_r(t_list **lst_a, t_list **lst_b);
t_list	*crrotirot_a(t_list *lst_a);
t_list	*crrotirot_b(t_list *lst_b);
void	crrotirot_r(t_list **lst_a, t_list **lst_b);

#endif
