/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/27 14:20:17 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* Verification of a chunk.
* If the chunk (midpoint) in settings contain only one number return 0.
* Otherwise return 1.
*/

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

/*
* Optimize the number of shots to set the biggest number in the top of B stack.
* After getting the biggest number in the top of the B stack, we push it on 
* the A stack.
*/

static void	order_b(t_vars *vars, int i_max)
{
	int	r;
	int	m;

	r = 1;
	m = vars->pb[i_max];
	if (vars->len_b / 2 >= i_max)
		r = 0;
	while (vars->pb[0] != m)
	{
		if (r == 0 || r == 1)
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		else if (r == 1)
			vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	}
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
}

/*
* Use to order the A stack when the first element of B stack is
* push on the A stack.
* Each time a new element is push on the stack A, we need to sort this element
* until the next element is biggest than this element.
*/

static void	reorder(t_vars *vars, int i)
{
	while (i >= 1)
	{
		if (i < vars->len_b - 1 && vars->pa[0] > vars->pb[0]
			&& vars->pa[vars->len_a - 1] < vars->pb[0])
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		}
		else if (i < vars->len_b - 1 && vars->pa[0] > vars->pb[1]
			&& vars->pa[vars->len_a - 1] < vars->pb[1] && i >= 1)
		{
			ft_swap(vars->pb, 'b');
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
		}
		vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
		i--;
		if (vars->len_b > 1 && vars->pb[0] < vars->pb[1])
			ft_swap(vars->pb, 'b');
	}
}

void	order_a(t_vars *vars)
{
	int	i;
	int	s;

	i = 0;
	if (vars->len_a > 0)
		s = vars->pa[0];
	while (i < vars->len_a - 1 && vars->pa[0] > vars->pa[1])
	{
		if (vars->pa[0] > vars->pa[1] && nb_sup(vars, s) > 1)
		{
			ss_or_sa(vars);
			if (i < vars->len_a - 1 && (vars->pa[0] > vars->pa[1]
					|| vars->pa[1] > vars->pa[2]))
			{
				vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
				i++;
			}
		}
		else if (nb_sup(vars, s) == 1)
			ft_swap(vars->pa, 'a');
		else if (nb_sup(vars, s) == 0)
			break ;
	}
	reorder(vars, i);
}

/*
* For the management of the last chunk.
* Use rrb and rb to sort in a decreasing order.
* After the ordre function we need to swap if it's needed in A stack.
*/

void	special_case(t_vars *vars)
{
	int	j;
	int	mx;

	while (vars->len_b)
	{
		mx = max(vars, vars->len_c - 1);
		j = 0;
		while (j < vars->len_b)
		{
			if (vars->pb[j] != mx)
				j++;
			else
				break ;
		}
		if (vars->len_b + vars->len_a < 103 && vars->len_b > 1
			&& vars->pb[0] < vars->pb[1])
			ft_swap(vars->pb, 'b');
		else
			order_b(vars, j);
		order_a(vars);
	}
}
