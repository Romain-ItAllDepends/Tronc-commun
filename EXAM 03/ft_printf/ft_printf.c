/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:57 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/02 15:48:49 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_puthex_fd(unsigned int n, char *base)
{
	int	x;

	x = 0;
	if (n > 15)
	{
		x += ft_puthex_fd(n / 16, base);
	}
	n = n % 16;
	x += ft_putchar_fd(base[n], 1);
	return (x);
}

int	ft_putstr_fd(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr_fd("(null)"));
	len = ft_strlen(s);
	write (1, s, len);
	return (len);
}

int	ft_putnbr_fd(int n)
{
	int	x;

	x = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		x += ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n >= 10)
	{
		x += ft_putnbr_fd(n / 10);
		n = n % 10;
	}
	x += ft_putchar_fd(n + '0', 1);
	return (x);
}

int	ft_type(char s, va_list print)
{
	if (s == 's')
		return (ft_putstr_fd(va_arg(print, char *)));
	else if (s == 'd')
		return (ft_putnbr_fd(va_arg(print, int)));
	else if (s == 'x')
		return (ft_puthex_fd(va_arg(print, int), "0123456789abcdef"));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	print;
	int		result;
	int		i;

	if (!s)
		return (-1);
	i = 0;
	result = 0;
	va_start (print, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			i++;
			result += ft_type(s[i], print);
		}
		else
		{
			write(1, &s[i], 1);
			result++;
		}
		i++;
	}
	va_end(print);
	return (result);
}
