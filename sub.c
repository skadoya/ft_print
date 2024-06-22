/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadoya <skadoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 20:58:39 by skadoya           #+#    #+#             */
/*   Updated: 2024/06/16 13:53:47 by skadoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_int(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	ft_putnbr(int n, int fd)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	count++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	return (NULL);
}
