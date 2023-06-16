/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:56:15 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/12 17:31:06 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf.h"

static void	ft_check_args(size_t currentArg, char c, int *count, int fd)
{
	if (c == 'c')
		ft_putchar_fd((char)currentArg, fd, count);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd((int)currentArg, fd, count);
	if (c == 's')
	{
		if (currentArg)
			ft_putstr_fd((char *)currentArg, fd, count);
		else
			ft_putstr_fd("(null)", fd, count);
	}
	if (c == 'u')
		ft_putunsigned(currentArg, fd, count);
	if (c == 'x')
		ft_print_hex(currentArg, 0, fd, count);
	if (c == 'X')
		ft_print_hex(currentArg, 1, fd, count);
	if (c == 'p')
	{
		if (currentArg)
			ft_print_addr(currentArg, fd, count, 1);
		else
			ft_putstr_fd("(nil)", fd, count);
	}
}

static void	ft_print_print(const char *str, int *count, va_list args, int fd)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] != '%')
			ft_putchar_fd(str[k], 1, count);
		else if (str[k] == '%' && str[k + 1] != '%')
		{
			ft_check_args(va_arg(args, unsigned long), str[k + 1], count, fd);
			k++;
		}
		else if (str[k] == '%' && str[k + 1] == '%')
		{
			ft_putchar_fd('%', 1, count);
			k++;
		}
		k++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		fd;

	fd = 1;
	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	ft_print_print(str, &count, args, fd);
	va_end(args);
	return (count);
}
