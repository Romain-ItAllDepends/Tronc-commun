/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:23:29 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/24 13:50:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static void	max_int(const char *str)
{
	if (ft_strlen(str) > 10)
	{
		write(2, "Too big number !\n", 18);
		exit(1);
	}
}

static void	error_max_int(long nb)
{
	if (nb >= 2147483648)
	{
		write(2, "Too big number !\n", 18);
		exit(1);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	int		mult;
	long	result;

	i = 0;
	mult = 1;
	result = 0;
	max_int(str);
	while (str && str[i] && (str[i] == ' '
			|| (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	if (str && str[i] && str[i] == '-')
	{
		mult = -1;
		i++;
	}
	else if (str && str[i] && str[i] == '+' && mult == 1)
		i++;
	while (str && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	error_max_int(result);
	return (result * mult);
}
