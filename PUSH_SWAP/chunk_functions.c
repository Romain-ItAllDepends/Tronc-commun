/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:28 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/29 11:12:35 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

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
			return (i);
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
			res = i;
		i++;
	}
	free(sort);
	return (res);
}

static int	*mid_and_range(int *list, int length, int newmidpoint)
{
	int	*newchunk;

	newchunk = malloc(sizeof(int) * 3);
	if (!newchunk)
		return (NULL);
	newchunk[0] = newmidpoint;
	newchunk[1] = start_chunk(list, length, newmidpoint);
	newchunk[2] = end_chunk(list, length, newmidpoint);
	return (newchunk);
}

/*
* A chunk is an area in which the midpoint and the range of index of your chunk.
* We need the chunk to send the integer in the stack b in the stack a.
* For the moment we need to find a solution to store the chunk the more 
* efficiently possible.
*/

int	**chunk_init(int newmidpoint, int *p, int **chunk)
{
	static int	length;
	int			**newchunk;
	int			i;

	if (length > 0)
		newchunk = malloc (sizeof(int *) * length);
	else
		newchunk = malloc (sizeof(int *));
	if (!newchunk)
		return (NULL);
	i = 0;
	while (i < length)
	{
		newchunk[i] = mid_and_range(p, length, newmidpoint);
		i++;
	}
	length++;
	free(chunk);
	return (newchunk);
}
