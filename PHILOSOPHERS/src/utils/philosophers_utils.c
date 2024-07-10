/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:13:32 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/10 07:24:28 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	args_are_digit(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == 0)
		{
			write(2, "Empty argument !\n", 17);
			exit(1);
		}
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
			{
				write(2, &args[i][j], 1);
				write(2, ": numeric argument required\n", 28);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	args_are_upper_zero(char **args)
{
	int	i;
	int	nb;

	i = 1;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		if (i == 1 && ft_atoi(args[i]) > 200)
		{
			write(2, "Too many philosophers !\n", 38);
			exit(1);
		}
		if (nb <= 0)
		{
			write(2, "Argument is bellow or equal to zero !\n", 38);
			exit(1);
		}
		i++;
	}
}
