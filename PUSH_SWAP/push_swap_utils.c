/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/22 15:35:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_split_initb(int **pa, int **pb, int *lengtha, int *lengthb)
{
	int	midpoint;
	int	i;

	i = 0;
	midpoint = ft_midpoint(*pa, *lengtha);
	while (i < (*lengtha / 2))
	{
		if (*pa[i] > midpoint)
		{
			ft_printf("kinder bueno");
			return (0);
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
	midpoint = ft_midpoint(*pb, *lengthb);
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

//Useless V

int	sort_bubble(int *tab, int length)
{
	int	temp;
	int	mid;
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
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j++] = temp;
			}
		}
		l--;
		i++;
	}
	mid = ft_midpoint(tab, length);
	return (mid);
}

int	ft_midpoint(int *tab, int length)
{
	int	mid;
	int	i;

	i = 0;
	mid = 0;
	while (i < length)
	{
		mid += tab[i];
		i++;
	}
	mid /= length;
	return (mid);
}
