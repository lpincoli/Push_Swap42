/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:56:32 by lpincoli          #+#    #+#             */
/*   Updated: 2022/11/21 15:23:06 by lpincoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/ft_push.h"

static	long	ft_atol(char *str)
{
	int		sign;
	long	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nmb *= 10;
		nmb += (*str - '0');
		str++;
	}
	return (nmb *= sign);
}

static	int	ft_strdigit(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static	int	is_int(char *str)
{
	long	check;

	check = ft_atol(str);
	if (check > 2147483647 || check < -2147483648)
		return (0);
	return (1);
}

static	int	check_doubles(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < ac)
	{
		while (j < ac)
		{
			if (atoi(av[i]) == atoi(av[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (check_doubles(ac, av))
		return (1);
	while (i < ac)
	{
		if ((av[i][0] != '-' && av[i][0] != '+') && (!ft_isdigit(av[i][0])))
			return (1);
		else if ((av[i][0] == '-' || av[i][0] == '+') && (!ft_isdigit(av[i][1])))
			return (1);
		else if (!ft_strdigit(av[i]))
			return (1);
		else if (!is_int(av[i]))
			return (1);
		i++;
	}
	return (0);
}
