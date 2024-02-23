/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:23:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/23 14:28:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	corner_print(t_vars *vars, mlx_t *mlx, int length_v, int length)
{
	vars->corner_high_left_i = mlx_texture_to_image(mlx,
			vars->corner_high_left_t);
	mlx_image_to_window(mlx, vars->corner_high_left_i, 0, 0);
	vars->corner_high_right_i = mlx_texture_to_image(mlx,
			vars->corner_high_right_t);
	mlx_image_to_window(mlx, vars->corner_high_right_i, 64 * length, 0);
	vars->corner_down_left_i = mlx_texture_to_image(mlx,
			vars->corner_down_left_t);
	mlx_image_to_window(mlx, vars->corner_down_left_i,
		64 * length, 64 * length_v);
	vars->corner_down_right_i = mlx_texture_to_image(mlx,
			vars->corner_down_right_t);
	mlx_image_to_window(mlx, vars->corner_down_right_i, 0, 64 * length_v);
}

void	wall_print(t_vars *vars, int length_v, int i, int j)
{
	mlx_t	*mlx;
	int		length;

	mlx = vars->mlx;
	length = ft_strlen(vars->map[0]) - 1;
	if (vars->map[i][j] == '1' && i == 0 && (j > 0 && j < length))
		mlx_image_to_window(mlx, vars->wall_high_i, 64 * j, 64 * i);
	else if (i == length_v && j > 0 && j < length)
		mlx_image_to_window(mlx, vars->wall_down_i, 64 * j, 64 * i);
	else if (i > 0 && i < length_v && j == 0)
		mlx_image_to_window(mlx, vars->wall_left_i, 64 * j, 64 * i);
	else if (i > 0 && i < length_v && j == length)
		mlx_image_to_window(mlx, vars->wall_right_i, 64 * j, 64 * i);
}

void	other_print(t_vars *vars, mlx_t	*mlx, int i, int j)
{
	int		length;

	length = ft_strlen(vars->map[0]) - 1;
	if (vars->map[i][j] == 'E')
	{
		vars->exit_i = mlx_texture_to_image(mlx, vars->exit_t);
		mlx_image_to_window(mlx, vars->exit_i, 64 * j, 64 * i);
	}
	else if (vars->map[i][j] == 'P')
	{
		mlx_image_to_window(mlx, vars->player_down_i, 64 * j, 64 * i);
		vars->i = i;
		vars->j = j;
	}
	else if (vars->map[i][j] == 'C')
		mlx_image_to_window(mlx, vars->collectable_i, 64 * j, 64 * i);
}

void	grass_and_bush_print(t_vars *vars, int length_v, int i, int j)
{
	int	length;

	length = ft_strlen(vars->map[0]) - 1;
	if (vars->map[i][j] == '1' && i != 0
		&& i != length_v && j != 0 && j != length)
		mlx_image_to_window(vars->mlx, vars->bush_i, 64 * j, 64 * i);
	else if (vars->map[i][j] == '0' || vars->map[i][j] == 'P'
	|| vars->map[i][j] == 'C')
		mlx_image_to_window(vars->mlx, vars->grass_i, 64 * j, 64 * i);
}
