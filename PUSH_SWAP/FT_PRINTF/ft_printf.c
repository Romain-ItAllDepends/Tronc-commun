/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:25:01 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/14 15:25:12 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char s, va_list print)
{
	if (s == 's')
		return (ft_putstr_fd(va_arg(print, char *), 1));
	else if (s == 'c')
		return (ft_putchar_fd(va_arg(print, int), 1));
	else if (s == 'd')
		return (ft_putnbr_fd(va_arg(print, int), 1));
	else if (s == 'i')
		return (ft_putnbr_fd(va_arg(print, int), 1));
	else if (s == 'u')
		return (ft_putnbru_fd(va_arg(print, int), 1));
	else if (s == 'x')
		return (ft_puthex_fd(va_arg(print, int), 1, "0123456789abcdef"));
	else if (s == 'X')
		return (ft_puthex_fd(va_arg(print, int), 1, "0123456789ABCDEF"));
	else if (s == 'p')
	{
		return (ft_putptr_fd(
				va_arg(print, unsigned long long), 1, "0123456789abcdef"));
	}
	else if (s == '%')
		return (ft_putchar_fd('%', 1));
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
