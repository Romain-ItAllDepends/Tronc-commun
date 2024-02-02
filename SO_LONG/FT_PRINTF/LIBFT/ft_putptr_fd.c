/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:55:27 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/14 14:55:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long long n, int fd, char *base)
{
	int			result;
	static int	x;

	if (!n)
		return (ft_putstr_fd("(nil)", fd));
	if (x++ == 0)
		write(fd, "0x", 2);
	result = 2;
	if (n >= 16)
		result = ft_putptr_fd(n / 16, fd, base);
	n = n % 16;
	result += ft_putchar_fd(base[n], fd);
	x = 0;
	return (result);
}
