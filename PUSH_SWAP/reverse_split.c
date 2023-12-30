/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/30 11:57:13 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*prepare(int lengtha, int lengthb)
{
	int	*tab;

	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	tab[0] = lengtha;
	tab[1] = lengthb;
	return (tab);
}

static void	is_ordered(pb, chunk)
{
		int	*sort;
	int	mid;
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
	
	return (0)
}

static void	decrease_order(int **pa, int **pb, int **chunk)
{
	int	j;

	j = 0;
	while (j < chunk[chunk[0][0]][1])
}

void	sort(int **pa, int **pb, int **chunk)
{
	int	i;
	int	j;

	i = 1;
	while (i < chunk[chunk[0][0]][1])
	{
		if (chunk[i][1] == chunk[i][2])
		{
			*pa = ft_push(*pa, chunk[chunk[0][0]][0], *pb[0], 'b');
			*pb = ft_push_balance(*pb, chunk[chunk[0][0]][2]);
		}
		else if (is_ordered(pb, chunk) == 1)
			decrease_order(int **pa, int **pb, int **chunk);
	}
}

/*
* Use the midpoint to sort the b stack and push it back in the stack a.
*/

void	reverse_split(int **pa, int **pb, int **chunk)
{
	int	length;
	int	lengtha;
	int	lengthb;

	length = chunk[0][0];
	lengtha = chunk[chunk[0][0]][0];
	lengthb = chunk[chunk[0][0]][1];
	sort(pa, pb, chunk);
}
