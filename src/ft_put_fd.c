/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:40:29 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/13 15:40:31 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd, count);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, count);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar_fd((nb + '0'), fd, count);
}
