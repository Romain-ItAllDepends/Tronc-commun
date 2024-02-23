/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:07:30 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/23 14:33:54 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	escape(t_vars *vars)
{
	ft_free(vars->map);
	free_images(vars);
	free_textures(vars);
	mlx_close_window(vars->mlx);
	mlx_terminate(vars->mlx);
	free(vars);
	exit(0);
}

void	down(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->player_down_i);
	mlx_delete_image(vars->mlx, vars->player_forward_i);
	mlx_delete_image(vars->mlx, vars->player_left_i);
	mlx_delete_image(vars->mlx, vars->player_right_i);
	vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
	vars->player_forward_i = mlx_texture_to_image(vars->mlx,
			vars->player_forward_t);
	vars->player_right_i = mlx_texture_to_image(vars->mlx,
			vars->player_right_t);
	vars->player_left_i = mlx_texture_to_image(vars->mlx,
			vars->player_left_t);
	vars->i++;
	mlx_image_to_window(vars->mlx, vars->player_down_i,
		64 * vars->j, 64 * vars->i);
	vars->nb_move++;
	ft_printf("You move already : %d times !\n", vars->nb_move);
	if (vars->map[vars->i][vars->j] == 'C')
	{
		vars->map[vars->i][vars->j] = '0';
		mlx_image_to_window(vars->mlx, vars->player_down_i,
			64 * vars->j, 64 * vars->i);
		reprint_collectable(vars);
	}
	if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		ft_win(vars);
}

void	up(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->player_down_i);
	mlx_delete_image(vars->mlx, vars->player_forward_i);
	mlx_delete_image(vars->mlx, vars->player_left_i);
	mlx_delete_image(vars->mlx, vars->player_right_i);
	vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
	vars->player_forward_i = mlx_texture_to_image(vars->mlx,
			vars->player_forward_t);
	vars->player_right_i = mlx_texture_to_image(vars->mlx,
			vars->player_right_t);
	vars->player_left_i = mlx_texture_to_image(vars->mlx,
			vars->player_left_t);
	vars->i--;
	mlx_image_to_window(vars->mlx, vars->player_forward_i,
		64 * vars->j, 64 * vars->i);
	vars->nb_move++;
	ft_printf("You move already : %d times !\n", vars->nb_move);
	if (vars->map[vars->i][vars->j] == 'C')
	{
		vars->map[vars->i][vars->j] = '0';
		mlx_image_to_window(vars->mlx, vars->player_forward_i,
			64 * vars->j, 64 * vars->i);
		reprint_collectable(vars);
	}
	if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		ft_win(vars);
}

void	left(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->player_down_i);
	mlx_delete_image(vars->mlx, vars->player_forward_i);
	mlx_delete_image(vars->mlx, vars->player_left_i);
	mlx_delete_image(vars->mlx, vars->player_right_i);
	vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
	vars->player_forward_i = mlx_texture_to_image(vars->mlx,
			vars->player_forward_t);
	vars->player_right_i = mlx_texture_to_image(vars->mlx,
			vars->player_right_t);
	vars->player_left_i = mlx_texture_to_image(vars->mlx,
			vars->player_left_t);
	vars->j--;
	mlx_image_to_window(vars->mlx, vars->player_left_i,
		64 * vars->j, 64 * vars->i);
	vars->nb_move++;
	ft_printf("You move already : %d times !\n", vars->nb_move);
	if (vars->map[vars->i][vars->j] == 'C')
	{
		vars->map[vars->i][vars->j] = '0';
		mlx_image_to_window(vars->mlx, vars->player_left_i,
			64 * vars->j, 64 * vars->i);
		reprint_collectable(vars);
	}
	if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		ft_win(vars);
}

void	right(t_vars *vars)
{
	mlx_delete_image(vars->mlx, vars->player_down_i);
	mlx_delete_image(vars->mlx, vars->player_forward_i);
	mlx_delete_image(vars->mlx, vars->player_left_i);
	mlx_delete_image(vars->mlx, vars->player_right_i);
	vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
	vars->player_forward_i = mlx_texture_to_image(vars->mlx,
			vars->player_forward_t);
	vars->player_right_i = mlx_texture_to_image(vars->mlx,
			vars->player_right_t);
	vars->player_left_i = mlx_texture_to_image(vars->mlx,
			vars->player_left_t);
	vars->j++;
	mlx_image_to_window(vars->mlx, vars->player_right_i,
		64 * vars->j, 64 * vars->i);
	vars->nb_move++;
	ft_printf("You move already : %d times !\n", vars->nb_move);
	if (vars->map[vars->i][vars->j] == 'C')
	{
		vars->map[vars->i][vars->j] = '0';
		mlx_image_to_window(vars->mlx, vars->player_right_i,
			64 * vars->j, 64 * vars->i);
		reprint_collectable(vars);
	}
	if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		ft_win(vars);
}
