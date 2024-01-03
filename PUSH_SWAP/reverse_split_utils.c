/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:43:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/03 11:34:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
* We will sort in a decreasing order each chunk starting by the chunk above
* the stack b.
*/

void	ft_chunk_check(t_vars *vars)
{
	int			i;
	int			j;
	static int	index_midpoint;

	j = 0;
	i = vars->len_c - 2;
	index_midpoint--;
	while (i > 0)
	{
		while (vars->chunk[i][2] != vars->pb[j])
			j++;
		while (j < vars->len_b)
		{
			if (j)
				j++;
			j++;
		}
		i--;
	}
}

/*
* Verification of a chunk.
* If the chunk (midpoint) in settings contain only one number return 0.
* Otherwise return 1.
*/

int	alone(int midpoint, t_vars *vars)
{
	int	i;
	int	ic;
	int	c;

	i = 0;
	while (ic < vars->len_c && vars->chunk[ic] != midpoint)
		ic++;
	while (i < vars->len_b && vars->pb[i] < vars->chunk[ic - 1])
		i++;
	j = i;
	while (i < vars->len_b)
		i++;
	if (i - j != 1)
		return (1);
	return (0);
}