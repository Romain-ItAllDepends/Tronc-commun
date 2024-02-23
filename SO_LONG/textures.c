/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:27:19 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/23 14:33:10 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures_s(t_vars *vars)
{
	if (vars->wall_down_t)
		mlx_delete_texture(vars->wall_down_t);
	if (vars->wall_left_t)
		mlx_delete_texture(vars->wall_left_t);
	if (vars->wall_right_t)
		mlx_delete_texture(vars->wall_right_t);
	if (vars->bush_t)
		mlx_delete_texture(vars->bush_t);
	if (vars->corner_high_left_t)
		mlx_delete_texture(vars->corner_high_left_t);
	if (vars->corner_high_right_t)
		mlx_delete_texture(vars->corner_high_right_t);
	if (vars->corner_down_left_t)
		mlx_delete_texture(vars->corner_down_left_t);
	if (vars->corner_down_right_t)
		mlx_delete_texture(vars->corner_down_right_t);
}

void	textures_verif(t_vars *vars)
{
	if (vars->collectable_t == NULL || vars->player_down_t == NULL
		|| vars->player_forward_t == NULL || vars->player_left_t == NULL
		|| vars->player_right_t == NULL || vars->exit_t == NULL
		|| vars->grass_t == NULL || vars->wall_high_t == NULL
		|| vars->wall_down_t == NULL || vars->wall_left_t == NULL
		|| vars->wall_right_t == NULL || vars->bush_t == NULL
		|| vars->corner_high_left_t == NULL || vars->corner_high_right_t == NULL
		|| vars->corner_down_left_t == NULL
		|| vars->corner_down_right_t == NULL)
		ft_error_four(vars);
}

void	reprint_collectable(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	mlx_delete_image(vars->mlx, vars->collectable_i);
	vars->nb_collectable--;
	vars->collectable_i = mlx_texture_to_image(vars->mlx, vars->collectable_t);
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
			{
				mlx_image_to_window(vars->mlx, vars->collectable_i,
					64 * j, 64 * i);
			}
			j++;
		}
		i++;
	}
}

void	init_img(t_vars *vars)
{
	vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
	vars->player_forward_i = mlx_texture_to_image(vars->mlx,
			vars->player_forward_t);
	vars->player_right_i = mlx_texture_to_image(vars->mlx,
			vars->player_right_t);
	vars->player_left_i = mlx_texture_to_image(vars->mlx, vars->player_left_t);
	vars->collectable_i = mlx_texture_to_image(vars->mlx, vars->collectable_t);
	vars->grass_i = mlx_texture_to_image(vars->mlx, vars->grass_t);
	vars->bush_i = mlx_texture_to_image(vars->mlx, vars->bush_t);
	vars->wall_right_i = mlx_texture_to_image(vars->mlx, vars->wall_right_t);
	vars->wall_left_i = mlx_texture_to_image(vars->mlx, vars->wall_left_t);
	vars->wall_down_i = mlx_texture_to_image(vars->mlx, vars->wall_down_t);
	vars->wall_high_i = mlx_texture_to_image(vars->mlx, vars->wall_high_t);
}
