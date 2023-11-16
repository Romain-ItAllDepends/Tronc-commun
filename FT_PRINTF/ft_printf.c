/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:08:36 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/16 15:54:23 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char s, va_list print)
{
	if (s == 's')
		return (ft_putstr_fd(va_arg(print, char *), 0));
	else if (s == 'c')
		return (ft_putchar_fd(va_arg(print, int), 0));
	else if (s == 'd')
		return (ft_putnbr_fd(va_arg(print, int), 0));
	else
		return (0);
}

int ft_printf(const char *s, ...)
{
	va_list print;
	int		result;
	int		i;

	i = 0;
	result = 0;
	va_start(print, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i] != '\0')
			result += ft_type(s[i], print);
		else
			ft_putchar_fd(s[i], 0);
		i++;
	}
	va_end(print);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("Chiffre = %d,\nLettre = %c\nString = %s\n", av[1], av[2], av[3]);
	return (0);
}
