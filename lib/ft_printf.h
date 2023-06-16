/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrangin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:23:57 by rfrangin          #+#    #+#             */
/*   Updated: 2022/10/12 15:25:33 by rfrangin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

void	ft_putunsigned(unsigned int nb, int fd, int *count);
void	ft_print_hex(unsigned int currentArg, int up_case, int fd, int *count);
void	ft_print_addr(unsigned long currentArg, int fd, int *count, int check);

#endif /* FT_PRINTF_H */
