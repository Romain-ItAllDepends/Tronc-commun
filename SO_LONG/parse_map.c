/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:29:52 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/23 14:30:55 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_textures(t_vars *vars)
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
	textures_verif(vars);
}

void	free_textures(t_vars *vars)
{
	if (vars->collectable_t)
		mlx_delete_texture(vars->collectable_t);
	if (vars->player_down_t)
		mlx_delete_texture(vars->player_down_t);
	if (vars->player_forward_t)
		mlx_delete_texture(vars->player_forward_t);
	if (vars->player_left_t)
		mlx_delete_texture(vars->player_left_t);
	if (vars->player_right_t)
		mlx_delete_texture(vars->player_right_t);
	if (vars->exit_t)
		mlx_delete_texture(vars->exit_t);
	if (vars->grass_t)
		mlx_delete_texture(vars->grass_t);
	if (vars->wall_high_t)
		mlx_delete_texture(vars->wall_high_t);
	free_textures_s(vars);
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
	init_img(vars);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			grass_and_bush_print(vars, length_v, i, j);
			wall_print(vars, length_v, i, j);
			other_print(vars, mlx, i, j);
			j++;
		}
		i++;
	}
	corner_print(vars, mlx, length_v, length);
}
