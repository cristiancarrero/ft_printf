/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:01:22 by marvin            #+#    #+#             */
/*   Updated: 2024/06/01 19:01:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int type_va(char c, va_list variable_arguments)
{
    if (c == 'c')
	ft_putchar(va_arg(variable_arguments, int));
    else if (c == 's')
    {
        char *str = va_arg(variable_arguments, char *);
        ft_putstr(str);
    }
	else if (c == 'p')
	{
		void *ptr = va_arg(variable_arguments, void *);
        print_address(ptr);
	}
	 else if (c == 'd' || c == 'i')
    {
        int num = va_arg(variable_arguments, int);
        ft_putnbr(num);
    }
	else if (c == 'u')
	{
		unsigned int neutral = va_arg(variable arguments, unsigned	int);
		ft_putnbr((int)neutral);

	}
    return 0;
}
int ft_printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            printed_chars += type_va(*(++format), args);
        }
        else
        {
            ft_putchar(*format);
            printed_chars++;
        }
        format++;
    }
    va_end(args);
    return printed_chars;
}