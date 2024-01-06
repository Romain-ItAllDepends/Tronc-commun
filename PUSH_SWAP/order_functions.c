/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:31:52 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 13:12:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int	ft_compare(int *pb, int *sort, int length);

int	decreasing(int *pb, int lengthb)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = -1;
	l = lengthb;
	sort = ft_fill(pb, lengthb);
	while (i++ < lengthb - 1)
	{
		j = -1;
		while (j++ < l - 2)
		{
			if (sort[j] < sort[j + 1])
				sort = ft_switch(sort, j);
		}
		l--;
	}
	i = ft_compare(pb, sort, lengthb);
	free(sort);
	return (i);
}

int	crescent(int *pb, int lengthb)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = lengthb;
	sort = ft_fill(pb, lengthb);
	while (i < lengthb)
	{
		j = 0;
		while (j < l - 1)
		{
			if (sort[j] > sort[j + 1])
				sort = ft_switch(sort, j);
			j++;
		}
		l--;
		i++;
	}
	i = ft_compare(pb, sort, lengthb);
	free(sort);
	return (i);
}

static int	ft_compare(int *pb, int *sort, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (pb[i] != sort[i])
			return (1);
		i++;
	}
	return (0);
}
