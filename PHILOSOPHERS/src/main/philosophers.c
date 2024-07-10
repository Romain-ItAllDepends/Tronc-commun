/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/10 07:31:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	parsing(int nb_arg, char **args)
{
	if (!(nb_arg == 5 || nb_arg == 6))
	{
		write (2, "Too many arguments !\n", 21);
		exit(1);
	}
	args_are_digit(args);
	args_are_upper_zero(args);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	parsing(ac, av);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (1);
	return (0);
}
