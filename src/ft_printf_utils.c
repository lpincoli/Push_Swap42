/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:37:48 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/13 15:37:50 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

void	ft_print_addr(unsigned long currentArg, int fd, int *count, int check)
{
	if (check)
		ft_putstr_fd("0x", fd, count);
	if (!currentArg)
		return ;
	if (currentArg >= 16)
	{
		ft_print_addr(currentArg / 16, fd, count, 0);
		currentArg = currentArg % 16;
	}
	ft_putchar_fd("0123456789abcdef"[currentArg], fd, count);
}

void	ft_putunsigned(unsigned int nb, int fd, int *count)
{
	long unsigned	n;

	n = nb;
	if (n >= 10)
	{
		ft_putunsigned(n / 10, fd, count);
		n = n % 10;
	}
	ft_putchar_fd((n + '0'), fd, count);
}

void	ft_print_hex(unsigned int currentArg, int up_case, int fd, int *count)
{
	unsigned long	n;

	n = currentArg;
	if (n >= 16)
	{
		ft_print_hex(n / 16, up_case, fd, count);
		n = n % 16;
	}
	if (up_case)
		ft_putchar_fd("0123456789ABCDEF"[n], fd, count);
	else
		ft_putchar_fd("0123456789abcdef"[n], fd, count);
}
