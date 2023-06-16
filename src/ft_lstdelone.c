/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:50:49 by lpincoli          #+#    #+#             */
/*   Updated: 2022/10/08 16:58:05 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	(*del)(lst->content);
	(*del)(lst->chunk);
	(*del)(lst->max);
	free(lst);
}
