/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:55:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/13 16:24:18 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	alone_push(t_vars *vars, int *verif, int ind);

static void	finish(t_vars *vars)
{
	int	j;
	int	length;

	j = 0;
	length = vars->len_b;
	while (j < length)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		j++;
	}
	return ;
}

/*

static void	decrease_order(t_vars *vars)
{
	int	j;

	j = 0;
	if (vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	while (j < vars->len_b)
	{
		ft_chunk_check(vars);
		j++;
	}
	return ;
}

*/

/*
* Use the midpoint to sort the b stack and push it back in the stack a.
* I think it's a better idea to while on the length of the chunk.
*/

void	reverse_split(t_vars *vars)
{
	int	i;
	int	v;
	int	length;

	i = 0;
	length = vars->len_c;
	while (i < length)
	{
		v = 0;
		if (alone(vars->chunk[i], vars) != 0 && i == 0)
			alone_push(vars, &v, i);
		else if (i > 0 && i != vars->len_c - 1)
			ft_chunk_check(vars, i, &v);
		else if (decreasing(vars->pb, vars->len_b) == 0)
		{
			finish(vars);
			break ;
		}
		else if (i == vars->len_c - 1)
			special_case(vars);
		if (crescent(vars->pa, vars->len_a) == 1)
			order_a(vars);
		if (v == 1)
			i++;
	}
}

int	*normalisation(int *p, int length)
{
	int	i;
	int	j;
	int	c;
	int	*np;

	np = malloc(sizeof(int) * length);
	if (np == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		j = 0;
		c = 0;
		while (j < length)
		{
			if (p[i] > p[j])
				c++;
			j++;
		}
		np[i] = c;
		i++;
	}
	return (np);
}

void	alone_push(t_vars *vars, int *verif, int ind)
{
	int	i;

	i = 0;
	*verif = 1;
	if (vars->len_b == 3)
	{
		vars->np = normalisation(vars->pb, vars->len_b);
		if (vars->np == 0)
			return ;
		ft_sort_three(vars);
		return ;
	}
	if (vars->len_a > 1 && vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	if (vars->len_b > 1 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	if (ind + 1 >= vars->len_c)
		ind -= 1;
	while (i < vars->len_b && vars->pb[0] <= vars->chunk[ind + 1])
	{
		order_a(vars);
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	}
}

void	ft_sort_three(t_vars *vars)
{
	if (vars->np[0] == 1 && vars->np[1] == 0)
		ft_swap(vars->pb, 'b');
	else if (vars->np[0] == 2 && vars->np[1] == 1)
	{
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		ft_swap(vars->pb, 'b');
	}
	else if (vars->np[0] == 2 && vars->np[1] == 0)
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
	else if (vars->np[0] == 0 && vars->np[1] == 2)
	{
		ft_swap(vars->pb, 'b');
		vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
	}
	else if (vars->np[0] == 1 && vars->np[1] == 2)
		vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	ft_swap(vars->pb, 'b');
	while (0 < vars->len_b)
	{
		vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
		vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	}
	free(vars->np);
}
