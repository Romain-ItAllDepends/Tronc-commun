/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/21 14:24:00 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_split_initb(int **pa, int **pb, int *lengtha, int *lengthb)
{
	int	*pb;
	int	i;

	i = 0;
	pb = NULL;
	while (i < (*lengtha / 2))
	{
		if (*pa[i] > *pa[*lengtha / 2])
		{
			pb = ft_push(pb, lengthb, *pa[0], 'b');
			*pa = ft_push_balance(*pa, lengtha);
		}
		else
			*pa = ft_rotate(pa, lengtha, 'a');
		i++;
	}
	return ((int *)pb);
}

int	*ft_split_inita(int **pb, int **pa, int *lengtha, int *lengthb)
{
	int	i;

	i = 0;
	while (i < (*lengthb / 2))
	{
		if (*pb[i] < *pb[*lengthb / 2])
		{
			*pa = ft_push(pb, lengthb, *pa[0], 'b');
			*pb = ft_push_balance(*pa, lengtha);
		}
		else
			*pb = ft_rotate(pb, lengthb, 'b');
		i++;
	}
	return ((int *)pa);
}

int	*sort_bubble(int *tab, length)
{
	int	temp;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = length;
	while (i < length)
	{
		j = 0;
		while (j < l)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		l--;
		i++;
	}
	return (tab);
}
