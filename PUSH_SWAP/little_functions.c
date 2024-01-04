/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:54:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/04 16:31:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	min_chunk(t_vars *vars, int index_midpoint)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len_b)
	{
		while (j < len_b && vars->pb[j] < vars->chunk[index_midpoint])
			j++;
		i++;
	}
	return (j);
}

int	max_chunk(t_vars *vars, int index_midpoint)
{
	int	i;

	i = 0;
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] < vars->pb[i])
			return (i);
		i++;
	}
	return (i + 1);
}

int	max(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = vars->pb[i];
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] < vars->pb[i] && j < vars->pb[i])
			j = vars->pb[i];
		i++;
	}
	return (j);
}