/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:54:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 14:47:52 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
* Use to get the first number bigger than n.
*/

int	nb_sup(t_vars *vars, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->len_a)
	{
		if (n > vars->pa[i])
			j++;
		i++;
	}
	return (j);
}

/*
* Get the range of the chunk.
* Normalement corriger mais pas sur d'etre ok avecle reste du code.
*/

int	min_chunk(t_vars *vars, int index_midpoint)
{
	int	i;

	i = 0;
	while (i < vars->len_b)
	{
		if (vars->pb[i] < vars->chunk[index_midpoint])
			return (i);
		i++;
	}
	return (0);
}

int	max_chunk(t_vars *vars, int index_midpoint)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->len_b)
	{
		if (vars->chunk[index_midpoint] < vars->pb[i])
			j++;
		i++;
	}
	return (j);
}

/*
* Biggest number of the stack.
*/

int	max(t_vars *vars, int index_midpoint)
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

void	reverse(t_vars *vars, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		vars ->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
		i++;
	}
}
