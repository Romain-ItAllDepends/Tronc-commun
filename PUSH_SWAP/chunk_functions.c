/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* A chunk is an area in which the midpoint and the range of index of your chunk.
* We need the chunk to send the integer in the stack b in the stack a.
*/

int	*chunk_init(int newmidpoint, t_vars *vars)
{
	int	*newchunk;
	int	i;

	vars->len_c++;
	newchunk = malloc (sizeof(int) * (vars->len_c));
	if (!newchunk)
		return (NULL);
	i = 0;
	newchunk[i] = newmidpoint;
	while (i < vars->len_c - 1)
	{
		i++;
		newchunk[i] = vars->chunk[i - 1];
	}
	if (vars->len_c > 1)
		free(vars->chunk);
	return (newchunk);
}

/*
* We will sort in a decreasing order each chunk starting by the chunk above
* the stack b.
* We will sort all the chunk other than the last one.
*/

void	ft_chunk_check(t_vars *vars, int ind)
{
	int	i;
	int	max;

	max = max_chunk(vars, ind);
	i = min_chunk(vars, ind);
	if (i - max <= 2 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	while (i < max)
	{
		if (vars->pb[0] > vars->pb[1])
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
			order_a(vars);
			i++;
		}
		else if (vars->pb[0] < vars->pb[1])
			ft_swap(vars->pb, 'b');
	}
}

int	select_chunk_size(int *sort, int length)
{
	int	mid;

	mid = 0;
	if (length < 53)
		mid = sort[length / 2];
	else if (length < 103)
		mid = sort[length / 4];
	else if (length < 253)
		mid = sort[length / 10];
	else if (length > 252)
		mid = sort[length / 20];
	free(sort);
	return (mid);
}
