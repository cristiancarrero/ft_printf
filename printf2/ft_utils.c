/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:55:06 by marvin            #+#    #+#             */
/*   Updated: 2024/06/01 23:55:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_address(void *ptr)
{
    unsigned long long int value = (unsigned long long int)ptr;
    ft_putstr("0x");
    if (value == 0)
    {
        ft_putchar('0');
        return;
    }
    while (value != 0)
    {
        int digit = value % 16;
        char hex_digit = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
        ft_putchar(hex_digit);
        value /= 16;
    }
}

void	ft_putnbr(int nb)
{
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}