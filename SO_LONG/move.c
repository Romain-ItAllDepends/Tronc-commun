/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:55:15 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/10 11:14:25 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	shift(t_vars *vars)
{
	if (mlx_is_key_down(vars->mlx, MLX_KEY_S))
	{
		if (vars->map[vars->i + 1][vars->j] != '1')
			down(vars);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_W))
	{
		if (vars->map[vars->i - 1][vars->j] != '1')
			up(vars);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_A))
	{
		if (vars->map[vars->i][vars->j - 1] != '1')
			left(vars);
	}
	if (mlx_is_key_down(vars->mlx, MLX_KEY_D))
	{
		if (vars->map[vars->i][vars->j + 1] != '1')
			right(vars);
	}
}

static void	key_press(mlx_key_data_t keydata, void *param)
{
	t_vars	*vars;

	vars = param;
	(void)keydata;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		escape(vars);
	shift(vars);
}

void	move(t_vars *vars, mlx_t *mlx)
{
	vars->nb_move = 0;
	mlx_key_hook(mlx, key_press, vars);
}
