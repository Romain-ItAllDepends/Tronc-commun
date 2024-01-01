/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/01 16:32:55 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_fill(int *tab, int length);
int	*ft_switch(int *sort, int j);

int	*ft_split_initb(t_vars *vars)
{
	int	midpoint;
	int	i;

	i = 0;
	midpoint = sort_bubble(vars->pa, vars->len_a);
	while (i < (vars->len_a / 2))
	{
		if (vars->pa[i] > midpoint)
		{
			vars->pb = ft_push(vars->pb, vars->len_b, vars->pa[0], 'b');
			vars->pa = ft_push_balance(vars->pa, vars->len_a);
		}
		else
			vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
		if (!(vars->pa[i] > midpoint))
			i++;
	}
	return ((int *)vars->pb);
}

int	*ft_split_inita(t_vars *vars)
{
	int	i;
	int	midpoint;

	i = 0;
	midpoint = sort_bubble(vars->pb, vars->len_b);
	if (midpoint == 0)
		return ((int *)vars->pa);
	while (i < vars->len_b)
	{
		if (vars->pb[i] < midpoint)
		{
			vars->pa = ft_push(vars->pa, vars->len_a, vars->pb[0], 'b');
			vars->pb = ft_push_balance(vars->pb, vars->len_b);
		}
		else if ((i + 1) < vars->len_b)
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		else
		{
			vars->pa = ft_push(vars->pa, vars->len_a, vars->pb[0], 'b');
			vars->pb = ft_push_balance(vars->pb, vars->len_b);
		}
		if (!(vars->pb[i] > midpoint))
			i++;
	}
	return ((int *)vars->pa);
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
	mid = sort[length / 2];
	free(sort);
	return (mid);
}

int	*ft_switch(int *sort, int j)
{
	int	temp;

	temp = sort[j + 1];
	sort[j + 1] = sort[j];
	sort[j] = temp;
	return (sort);
}

int	*ft_fill(int *tab, int length)
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
