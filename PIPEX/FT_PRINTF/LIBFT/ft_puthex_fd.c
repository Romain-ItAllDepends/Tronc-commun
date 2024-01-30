/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:54:28 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/14 14:54:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned int n, int fd, char *base)
{
	int	x;

	x = 0;
	if (n > 15)
	{
		x += ft_puthex_fd(n / 16, fd, base);
	}
	n = n % 16;
	x += ft_putchar_fd(base[n], fd);
	return (x);
}
