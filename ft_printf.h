/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skadoya <skadoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:39:03 by skadoya           #+#    #+#             */
/*   Updated: 2024/06/16 13:52:00 by skadoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar_int(char c, int fd);
int	ft_putstr_int(char *s, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putptr_fd(void *ptr, int fd);
int	ft_putnbr_base_fd(unsigned long long n, int base, int upper, int fd);
int	ft_printf(const char *format, ...);
int	write_str(char *str);
int	format_check(const char *format, va_list args, int printed_chars);

#endif
