/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:29:52 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/03 03:40:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_vars *vars)
{
	vars->collectable_t = mlx_load_png("textures/collectable.png");
	vars->player_down_t = mlx_load_png("textures/player_down.png");
	vars->player_forward_t = mlx_load_png("textures/player_forward.png");
	vars->player_left_t = mlx_load_png("textures/player_left.png");
	vars->player_right_t = mlx_load_png("textures/player_right.png");
	vars->exit_t = mlx_load_png("textures/exit.png");
	vars->grass_t = mlx_load_png("textures/grass.png");
	vars->wall_high_t = mlx_load_png("textures/wall_high.png");
	vars->wall_down_t = mlx_load_png("textures/wall_down.png");
	vars->wall_left_t = mlx_load_png("textures/wall_left.png");
	vars->wall_right_t = mlx_load_png("textures/wall_right.png");
	vars->bush_t = mlx_load_png("textures/bush.png");
	vars->corner_high_left_t = mlx_load_png("textures/corner_high_left.png");
	vars->corner_high_right_t = mlx_load_png("textures/corner_high_right.png");
	vars->corner_down_left_t = mlx_load_png("textures/corner_down_left.png");
	vars->corner_down_right_t = mlx_load_png("textures/corner_down_right.png");
}

void	free_textures(t_vars *vars)
{
	mlx_delete_texture(vars->collectable_t);
	mlx_delete_texture(vars->player_down_t);
	mlx_delete_texture(vars->player_forward_t);
	mlx_delete_texture(vars->player_left_t);
	mlx_delete_texture(vars->player_right_t);
	mlx_delete_texture(vars->exit_t);
	mlx_delete_texture(vars->grass_t);
	mlx_delete_texture(vars->wall_high_t);
	mlx_delete_texture(vars->wall_down_t);
	mlx_delete_texture(vars->wall_left_t);
	mlx_delete_texture(vars->wall_right_t);
	mlx_delete_texture(vars->bush_t);
	mlx_delete_texture(vars->corner_high_left_t);
	mlx_delete_texture(vars->corner_high_right_t);
	mlx_delete_texture(vars->corner_down_left_t);
	mlx_delete_texture(vars->corner_down_right_t);
}

void	free_images(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->collectable_i);
	mlx_delete_image(vars->mlx, vars->player_down_i);
	mlx_delete_image(vars->mlx, vars->player_forward_i);
	mlx_delete_image(vars->mlx, vars->player_left_i);
	mlx_delete_image(vars->mlx, vars->player_right_i);
	mlx_delete_image(vars->mlx, vars->exit_i);
	mlx_delete_image(vars->mlx, vars->grass_i);
	mlx_delete_image(vars->mlx, vars->wall_high_i);
	mlx_delete_image(vars->mlx, vars->wall_down_i);
	mlx_delete_image(vars->mlx, vars->wall_left_i);
	mlx_delete_image(vars->mlx, vars->wall_right_i);
	mlx_delete_image(vars->mlx, vars->bush_i);
	mlx_delete_image(vars->mlx, vars->corner_high_left_i);
	mlx_delete_image(vars->mlx, vars->corner_high_right_i);
	mlx_delete_image(vars->mlx, vars->corner_down_left_i);
	mlx_delete_image(vars->mlx, vars->corner_down_right_i);
}

void	parse_map(t_vars *vars, mlx_t *mlx)
{
	int	i;
	int	j;
	int	length;
	int	length_v;

	length = ft_strlen(vars->map[0]) - 1;
	length_v = ft_strlen_mod(vars->map) - 1;
	init_textures(vars);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == 'P'
			|| vars->map[i][j] == 'C')
			{
				vars->grass_i = mlx_texture_to_image(mlx, vars->grass_t);
				mlx_image_to_window(mlx, vars->grass_i, 64 * j, 64 * i);
			}
			if (vars->map[i][j] == 'E')
			{
				vars->exit_i = mlx_texture_to_image(mlx, vars->exit_t);
				mlx_image_to_window(mlx, vars->exit_i, 64 * j, 64 * i);
			}
			if (vars->map[i][j] == 'P')
			{
				vars->player_down_i = mlx_texture_to_image(mlx, vars->player_down_t);
				mlx_image_to_window(mlx, vars->player_down_i, 64 * j, 64 * i);
				vars->i = i;
				vars->j = j;
			}
			if (vars->map[i][j] == 'C')
			{
				vars->collectable_i = mlx_texture_to_image(mlx, vars->collectable_t);
				mlx_image_to_window(mlx, vars->collectable_i, 64 * j, 64 * i);
			}
			else if (vars->map[i][j] == '1' && i == 0 && (j > 0 && j < length))
			{
				vars->wall_high_i = mlx_texture_to_image(mlx, vars->wall_high_t);
				mlx_image_to_window(mlx, vars->wall_high_i, 64 * j, 64 * i);
			}
			else if (i == length_v && j > 0 && j < length)
			{
				vars->wall_down_i = mlx_texture_to_image(mlx, vars->wall_down_t);
				mlx_image_to_window(mlx, vars->wall_down_i, 64 * j, 64 * i);
			}
			else if (i > 0 && i < length_v && j == 0)
			{
				vars->wall_left_i = mlx_texture_to_image(mlx, vars->wall_left_t);
				mlx_image_to_window(mlx, vars->wall_left_i, 64 * j, 64 * i);
			}
			else if (i > 0 && i < length_v && j == length)
			{
				vars->wall_right_i = mlx_texture_to_image(mlx, vars->wall_right_t);
				mlx_image_to_window(mlx, vars->wall_right_i, 64 * j, 64 * i);
			}
			else if (vars->map[i][j] == '1' && i !=0 && i != length_v && j != 0 && j != length)
			{
				vars->bush_i = mlx_texture_to_image(mlx, vars->bush_t);
				mlx_image_to_window(mlx, vars->bush_i, 64 * j, 64 * i);
			}
			j++;
		}
		i++;
	}
	vars->corner_high_left_i = mlx_texture_to_image(mlx, vars->corner_high_left_t);
	mlx_image_to_window(mlx, vars->corner_high_left_i, 0, 0);

	vars->corner_high_right_i = mlx_texture_to_image(mlx, vars->corner_high_right_t);
	mlx_image_to_window(mlx, vars->corner_high_right_i, 64 * length, 0);

	vars->corner_down_left_i = mlx_texture_to_image(mlx, vars->corner_down_left_t);
	mlx_image_to_window(mlx, vars->corner_down_left_i, 64 * length, 64 * length_v);

	vars->corner_down_right_i = mlx_texture_to_image(mlx, vars->corner_down_right_t);
	mlx_image_to_window(mlx, vars->corner_down_right_i, 0, 64 * length_v);
}
