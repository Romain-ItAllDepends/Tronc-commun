/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	decreasing(int *pb, int lengthb)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	l = lengthb;
	sort = ft_fill(pb, lengthb);
	while (i < lengthb - 1)
	{
		j = 0;
		while (j < l - 1)
		{
			if (sort[j] < sort[j + 1])
				sort = ft_switch(sort, j);
			j++;
		}
		i++;
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

void	ft_four(t_vars *vars)
{
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	if (vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	if (vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	free(vars->pb);
}
