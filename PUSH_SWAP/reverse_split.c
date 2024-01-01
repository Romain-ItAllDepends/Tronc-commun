/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/01 15:49:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	finish(int **pa, int **pb, int ***chunk)
{
	int	j;

	j = 0;
	if (decreasing(vars->pb, vars->len_b) == 0)
	{
		while (j < vars->len_b)
		{
			vars->pa = ft_push(vars->pa, vars->len_a, vars->pb[0], 'b');
			vars->pb = ft_push_balance(vars->pb, vars->len_b);
			j++;
		}
	}
	return ;
}

static void	decrease_order(t_vars *vars)
{
	int	j;

	j = 0;
	if (vars->pb[0] < vars->pb[1])
		vars->pb = ft_swap(vars->pb, 'b');
	while (j < vars->len_b)
	{
		ft_chunk_check(vars);
		j++;
	}
	return ;
}

void	sort(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_b)
	{
		if (vars->chunk[i][1] == vars->chunk[i][2])
		{
			*pa = ft_push(&vars->pa, &vars->len_a, vars->pb[0], 'b');
			*pb = ft_push_balance(&vars->pb, &vars->len_b);
		}
		else if (decreasing(vars->pb, vars->len_b) == 1)
			decrease_order(vars);
		else
		{
			finish(vars);
			break ;
		}
		i++;
	}
}

/*
* Use the midpoint to sort the b stack and push it back in the stack a.
*/

void	reverse_split(t_vars *vars)
{
	int	length;
	int	lengtha;
	int	lengthb;

	length = chunk[0][0];
	lengtha = chunk[chunk[0][0]][0];
	lengthb = chunk[chunk[0][0]][1];
	sort(vars);
}
