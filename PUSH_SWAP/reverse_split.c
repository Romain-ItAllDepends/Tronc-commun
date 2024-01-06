/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 13:55:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	alone_push(t_vars *vars);

static void	finish(t_vars *vars)
{
	int	j;
	int	length;

	j = 0;
	length = vars->len_b;
	while (j < length)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		j++;
	}
	return ;
}

/*

static void	decrease_order(t_vars *vars)
{
	int	j;

	j = 0;
	if (vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	while (j < vars->len_b)
	{
		ft_chunk_check(vars);
		j++;
	}
	return ;
}

*/

/*
* Use the midpoint to sort the b stack and push it back in the stack a.
* I think it's a better idea to while on the length of the chunk.
*/

void	reverse_split(t_vars *vars)
{
	int	i;
	int	length;

	i = 0;
	length = vars->len_b;
	while (i < length)
	{
		if (alone(vars->chunk[vars->len_c - 1], vars) != 0)
			alone_push(vars);
		else if (decreasing(vars->pb, vars->len_b) == 1 && i != vars->len_c)
			ft_chunk_check(vars, i);
		else if (decreasing(vars->pb, vars->len_b) == 0)
		{
			finish(vars);
			break ;
		}
		else if (i == vars->len_c)
			special_case(vars);
		if (crescent(vars->pa, vars->len_a) == 1)
			order_a(vars); // reverse(); maybe
		i++;
	}
}

void	alone_push(t_vars *vars)
{
	if (vars->len_a > 1 && vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	if (vars->len_b > 1 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'b');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
}
