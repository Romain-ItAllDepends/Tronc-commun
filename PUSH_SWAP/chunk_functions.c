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
