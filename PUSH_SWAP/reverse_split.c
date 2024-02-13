/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/12 12:37:50 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	push_to_stack_a(t_vars *vars)
{
	int	n;
	int	j;

	j = 0;
	n = nb_max(vars->pb, vars->len_b);
	while (vars->pb[j] != n)
		j++;
	j = verif_and_push(vars, j);
	if (j != 0)
		exit(1);
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
		{
			while (vars->len_b != 0)
				push_to_stack_a(vars);
		}
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
