/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/10 12:56:49 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 2);
	if (!vars || ac != 2)
	{
		if (vars)
			free(vars);
		write (2, "Error\n", 6);
		exit(1);
	}
	init_map(av[1], vars);
	finishable(vars);
	vars->mlx = mlx_init(ft_strlen(vars->map[0]) * 100,
			ft_strlen_mod(vars->map) * 100, "SO_LONG", false);
	vars->player_down_t = mlx_load_png("textures/player_down.png");
	mlx_set_icon(vars->mlx, vars->player_down_t);
	mlx_delete_texture(vars->player_down_t);
	parse_map(vars, vars->mlx);
	move(vars, vars->mlx);
	mlx_loop(vars->mlx);
	mlx_terminate(vars->mlx);
	return (0);
}
