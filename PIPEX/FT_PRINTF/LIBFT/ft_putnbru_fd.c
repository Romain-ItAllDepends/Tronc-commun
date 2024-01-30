/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:55:15 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/14 14:55:18 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	int	result;

	result = 0;
	if (n >= 10)
	{
		result += ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	result += ft_putchar_fd(n + '0', fd);
	return (result);
}
