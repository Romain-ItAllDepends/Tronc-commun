/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:08:36 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/16 15:13:07 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *s, ...)
{
	va_list print;
	int		i;

	i = 0;
	va_start(print, s);
	while (s[i])
	{
		printf("%s ", va_arg(print, char *));
		i++;
	}
	va_end(print);
	return (0);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("Star", "J'aime", "les", "kinder", "bueno");
	return (0);
}
