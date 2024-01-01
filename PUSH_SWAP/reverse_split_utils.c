/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:43:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/01 15:46:40 by rgobet           ###   ########.fr       */
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
	static int	index_midpoint = i + 1;

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
