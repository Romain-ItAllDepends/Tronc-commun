/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/02 19:08:56 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_vars	*vars;
	mlx_t	*mlx;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars || ac != 2)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	init_map(av[1], vars);
	finishable(vars);
	mlx = mlx_init(ft_strlen(vars->map[0]) * 100, ft_strlen_mod(vars->map) * 100, "SO_LONG", false);
	
	
	mlx_image_t* img = mlx_new_image(mlx, 64, 64);

	vars->player_left_t = mlx_load_png("textures/player_left.png");
	vars->player_left_i = mlx_texture_to_image(mlx, vars->player_left_t);
	mlx_image_to_window(mlx, vars->player_left_i, 64, 64);

	// Display an instance of the image
	mlx_image_to_window(mlx, img, 0, 0);


	mlx_loop(mlx);
	ft_free(vars->map);
	free(vars);
	return (0);
}
