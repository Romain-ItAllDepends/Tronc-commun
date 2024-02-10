/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:25:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/10 10:02:00 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_one(t_vars *vars)
{
	write (2, "Error\n", 6);
	free(vars);
	exit(1);
}

void	ft_error_two(t_vars *vars, char **tab)
{
	write (2, "Error\n", 6);
	ft_free(vars->map);
	ft_free(tab);
	free(vars);
	exit(1);
}

void	ft_error_three(t_vars *vars)
{
	write (2, "Error\n", 6);
	ft_free(vars->map);
	free(vars);
	exit(1);
}

void	ft_error_four(t_vars *vars)
{
	ft_free(vars->map);
	free_images(vars);
	free_textures(vars);
	ft_printf("Congratulation, you win !");
	mlx_close_window(vars->mlx);
	mlx_terminate(vars->mlx);
	free(vars);
	exit(0);
}
