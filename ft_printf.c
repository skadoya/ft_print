/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadoya <skadoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:43:01 by skadoya           #+#    #+#             */
/*   Updated: 2024/06/16 14:06:03 by skadoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	address;
	int					count;

	count = 0;
	address = (unsigned long long)ptr;
	ft_putstr_fd("0x", fd);
	count += 2;
	count += ft_putnbr_base_fd(address, 16, 0, fd);
	return (count);
}

int	ft_putnbr_base_fd(unsigned long long n, int base, int upper, int fd)
{
	char	*digits;
	int		count;

	count = 0;
	if (upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= (unsigned int)base)
		count += ft_putnbr_base_fd(n / base, base, upper, fd);
	count++;
	ft_putchar_fd(digits[n % base], fd);
	return (count);
}

int	write_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_putstr_int("(null)", 1));
	count = ft_putstr_int(str, 1);
	return (count);
}

int	format_check(const char *format, va_list args, int printed_chars)
{
	char	c;

	if (*format == 'c')
	{
		c = va_arg(args, int);
		printed_chars += ft_putchar_int(c, 1);
	}
	if (*format == 's')
		printed_chars += write_str(va_arg(args, char *));
	if (*format == 'p')
		printed_chars += ft_putptr_fd(va_arg(args, void *), 1);
	if (*format == 'd' || *format == 'i')
		printed_chars += ft_putnbr(va_arg(args, int), 1);
	if (*format == 'u')
		printed_chars += ft_putnbr_base_fd((unsigned int)va_arg(args, int),
				10, 0, 1);
	if (*format == 'x')
		printed_chars += ft_putnbr_base_fd(va_arg(args, unsigned int),
				16, 0, 1);
	if (*format == 'X')
		printed_chars += ft_putnbr_base_fd(va_arg(args, unsigned int),
				16, 1, 1);
	if (*format == '%')
		printed_chars += ft_putchar_int('%', 1);
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, format);
	if (format == NULL)
	{
		va_end(args);
		return (0);
	}
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed_chars = format_check(format, args, printed_chars);
		}
		else
			printed_chars += ft_putchar_int(*format, 1);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
