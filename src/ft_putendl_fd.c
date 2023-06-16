/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:13:59 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/07 23:15:37 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 1;
	ft_putstr_fd(s, fd, &count);
	ft_putchar_fd('\n', fd, &count);
}
