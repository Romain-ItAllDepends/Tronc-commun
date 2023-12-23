/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/23 14:25:28 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int	*ft_fill(int *tab, int length);
static int	*ft_switch(int *sort, int j);

int	*ft_split_initb(int **pa, int **pb, int *lengtha, int *lengthb)
{
	int	midpoint;
	int	i;

	i = 0;
	midpoint = sort_bubble(*pa, *lengtha);
	while (i < (*lengtha / 2))
	{
		if (*pa[i] > midpoint)
		{
			/*ft_printf("kinder bueno");
			return (0);*/
			*pb = ft_push(*pb, lengthb, *pa[0], 'b');
			*pa = ft_push_balance(*pa, lengtha);
		}
		else
			*pa = ft_rotate(*pa, *lengtha, 'a');
		i++;
	}
	return ((int *)pb);
}

int	*ft_split_inita(int **pb, int **pa, int *lengtha, int *lengthb)
{
	int	i;
	int	midpoint;

	i = 0;
	midpoint = sort_bubble(*pb, *lengthb);
	while (i < (*lengthb / 2))
	{
		if (*pb[i] < midpoint)
		{
			*pa = ft_push(*pb, lengthb, *pa[0], 'b');
			*pb = ft_push_balance(*pa, lengtha);
		}
		else
			*pb = ft_rotate(*pb, *lengthb, 'b');
		i++;
	}
	return ((int *)pa);
}

//Trieur et midpoint maker

int	sort_bubble(int *tab, int length)
{
	int	*sort;
	int	mid;
	int	i;
	int	j;
	int	l;

	i = 0;
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
	mid = sort[length / 2];
	free(sort);
	return (mid);
}

static int	*ft_switch(int *sort, int j)
{
	int	temp;

	temp = sort[j + 1];
	sort[j + 1] = sort[j];
	sort[j] = temp;
	return (sort);
}

static int	*ft_fill(int *tab, int length)
{
	int	i;
	int	*res;

	res = malloc (length * sizeof(int));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}