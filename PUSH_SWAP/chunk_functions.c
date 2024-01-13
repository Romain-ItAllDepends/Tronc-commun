/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:28 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/11 16:05:53 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
static int	*sort_b(int	*tab, int length)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	if (length == 0)
		return (0);
	l = length;
	sort = ft_fill(tab, length);
	while (i < length)
	{
		j = -1;
		while (j++ < l - 2)
		{
			if (sort[j] > sort[j + 1])
				sort = ft_switch(sort, j);
		}
		l--;
		i++;
	}
	return (sort);
}

*/

/*
* Find an algorithme to find the start and the end of each chunk.
* Not used for the moment.
*/

/*

static int	start_chunk(int *list, int length, int midpoint)
{
	int	i;
	int	*sort;

	i = 0;
	sort = sort_b(list, length);
	if (!sort)
		return (-1);
	while (i < length)
	{
		if (sort[i] < midpoint)
		{
			free(sort);
			return (sort[i]);
		}
		i++;
	}
	free(sort);
	return (-1);
}

static int	end_chunk(int *list, int length, int midpoint)
{
	int	i;
	int	res;
	int	*sort;

	i = 0;
	res = -1;
	sort = sort_b(list, length);
	if (!sort)
		return (-1);
	while (i < length)
	{
		if (sort[i] < midpoint)
			res = sort[i];
		i++;
	}
	free(sort);
	return (res);
}
*/

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
	// i = 0;
	// while (i < vars->len_c)
	// {
	// 	ft_printf("\n%d", newchunk[i]);
	// 	i++;
	// }
	// ft_printf("\n\n\n\n%d\n\n\n\n\n", vars->len_c);
	return (newchunk);
}
