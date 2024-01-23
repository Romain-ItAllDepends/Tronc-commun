/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alone(int midpoint, t_vars *vars)
{
	int	i;
	int	j;
	int	ac;

	i = 0;
	j = 0;
	ac = 0;
	while (vars->chunk[ac] != midpoint)
		ac++;
	if (ac == 0 && vars->len_b == 1)
		return (1);
	else if (ac == vars->len_c - 1 && vars->len_b == 1)
		return (1);
	else if (ac == vars->len_c - 1)
		return (0);
	while (i < vars->len_b)
	{
		if (midpoint > vars->pb[i] && vars->pb[i] >= vars->chunk[ac + 1])
			j++;
		i++;
	}
	if (j == 1)
		return (1);
	return (0);
}

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
* Use the midpoint to sort the b stack and push it back in the stack a.
* I think it's a better idea to while on the length of the chunk.
*/

void	reverse_split(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_c)
	{
		if (alone(vars->chunk[i], vars) != 0)
			alone_push(vars);
		else if (i < vars->len_c - 1)
			ft_chunk_check(vars, i);
		else if (decreasing(vars->pb, vars->len_b) == 0)
		{
			finish(vars);
			break ;
		}
		else if (i == vars->len_c - 1)
			special_case(vars);
		if (crescent(vars->pa, vars->len_a) == 1)
			order_a(vars);
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

void	alone_push(t_vars *vars)
{
	if (vars->len_a > 1 && vars->pa[0] > vars->pa[1])
		ft_swap(vars->pa, 'a');
	if (vars->len_b > 1 && vars->pb[0] < vars->pb[1])
		ft_swap(vars->pb, 'b');
	order_a(vars);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	order_a(vars);
}
