/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/03 11:26:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	finish(t_vars *vars)
{
	int	j;

	j = 0;
	while (j < vars->len_b)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		j++;
	}
	return ;
}

static void	decrease_order(t_vars *vars)
{
	int	j;

	j = 0;
	if (vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	while (j < vars->len_b)
	{
		//ft_chunk_check(vars);
		j++;
	}
	return ;
}

/*
* Use the midpoint to sort the b stack and push it back in the stack a.
*/

void	reverse_split(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_b)
	{
		if (alone(vars->chunk[vars->len_c], vars) != 0)
		{
			ft_push(vars->pa, &vars->len_a, vars->pb[0], 'b');
			ft_push_balance(vars->pb, &vars->len_b);
		}
		else if (decreasing(vars->pb, vars->len_b) == 1)
			decrease_order(vars);
		else if (decreasing(vars->pb, vars->len_b) == 0)
		{
			finish(vars);
			break ;
		}
		i++;
	}
}
