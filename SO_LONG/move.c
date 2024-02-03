/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:55:15 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/03 02:56:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv(mlx_key_data_t keydata, void *param)
{
	t_vars *vars = param;
	(void)keydata;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		if (vars->map[vars->i + 1][vars->j] != '1')
		{
			mlx_delete_image(vars->mlx, vars->player_down_i);
			mlx_delete_image(vars->mlx, vars->player_forward_i);
			mlx_delete_image(vars->mlx, vars->player_left_i);
			mlx_delete_image(vars->mlx, vars->player_right_i);
			vars->i++;
			vars->player_down_i = mlx_texture_to_image(vars->mlx, vars->player_down_t);
			mlx_image_to_window(vars->mlx, vars->player_down_i, 64 * vars->j, 64 * vars->i);
			vars->nb_move++;
			ft_printf("You move already : %d times !\n", vars->nb_move);
		}
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			mlx_delete_image(vars->mlx, vars->collectable_i);
			vars->nb_collectable--;
		}
		if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		{
			ft_free(vars->map);
			free(vars);
			ft_printf("Congratulation, you win !");
			mlx_close_window(vars->mlx);
		}
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		if (vars->map[vars->i - 1][vars->j] != '1')
		{
			mlx_delete_image(vars->mlx, vars->player_down_i);
			mlx_delete_image(vars->mlx, vars->player_forward_i);
			mlx_delete_image(vars->mlx, vars->player_left_i);
			mlx_delete_image(vars->mlx, vars->player_right_i);
			vars->i--;
			vars->player_forward_i = mlx_texture_to_image(vars->mlx, vars->player_forward_t);
			mlx_image_to_window(vars->mlx, vars->player_forward_i, 64 * vars->j, 64 * vars->i);
			vars->nb_move++;
			ft_printf("You move already : %d times !\n", vars->nb_move);
		}
		if (vars->map[vars->i][vars->j] == 'C')
		{
			vars->map[vars->i][vars->j] = '0';
			mlx_delete_image(vars->mlx, vars->collectable_i);
			vars->nb_collectable--;
		}
		if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
		{
			ft_free(vars->map);
			free(vars);
			ft_printf("Congratulation, you win !");
			mlx_close_window(vars->mlx);
		}
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	{
		if (vars->map[vars->i][vars->j - 1] != '1')
		{
			mlx_delete_image(vars->mlx, vars->player_down_i);
			mlx_delete_image(vars->mlx, vars->player_forward_i);
			mlx_delete_image(vars->mlx, vars->player_left_i);
			mlx_delete_image(vars->mlx, vars->player_right_i);
			vars->j--;
			vars->player_left_i = mlx_texture_to_image(vars->mlx, vars->player_left_t);
			mlx_image_to_window(vars->mlx, vars->player_left_i, 64 * vars->j, 64 * vars->i);
			vars->nb_move++;
			ft_printf("You move already : %d times !\n", vars->nb_move);
			if (vars->map[vars->i][vars->j] == 'C')
			{
				vars->map[vars->i][vars->j] = '0';
				mlx_delete_image(vars->mlx, vars->collectable_i);
				vars->nb_collectable--;
			}
			if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
			{
				ft_free(vars->map);
				free(vars);
				ft_printf("Congratulation, you win !");
				mlx_close_window(vars->mlx);
			}
		}
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		if (vars->map[vars->i][vars->j + 1] != '1')
		{
			mlx_delete_image(vars->mlx, vars->player_down_i);
			mlx_delete_image(vars->mlx, vars->player_forward_i);
			mlx_delete_image(vars->mlx, vars->player_left_i);
			mlx_delete_image(vars->mlx, vars->player_right_i);
			vars->j++;
			vars->player_right_i = mlx_texture_to_image(vars->mlx, vars->player_right_t);
			mlx_image_to_window(vars->mlx, vars->player_right_i, 64 * vars->j, 64 * vars->i);
			vars->nb_move++;
			ft_printf("You move already : %d times !\n", vars->nb_move);
			if (vars->map[vars->i][vars->j] == 'C')
			{
				vars->map[vars->i][vars->j] = '0';
				mlx_delete_image(vars->mlx, vars->collectable_i);
				vars->nb_collectable--;
			}
			if (vars->map[vars->i][vars->j] == 'E' && vars->nb_collectable == 0)
			{
				vars->map[vars->i][vars->j] = '0';
				mlx_delete_image(vars->mlx, vars->exit_i);
				ft_free(vars->map);
				free(vars);
				free_images(vars);
				free_textures(vars);
				ft_printf("Congratulation, you win !");
				mlx_close_window(vars->mlx);
			}
		}
	}
}

void	move(t_vars *vars, mlx_t *mlx)
{
	vars->nb_move = 0;
	mlx_key_hook(mlx, mv, vars);
}
