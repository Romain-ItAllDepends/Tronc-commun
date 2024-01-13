/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:43:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/13 13:37:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
* We will sort in a decreasing order each chunk starting by the chunk above
* the stack b.
* m = midpoint
* We will sort all the chunk other than the last one.
*/

void	ft_chunk_check(t_vars *vars, int ind, int *v)
{
	int	i;
	int	max;
	int	m;

	max = max_chunk(vars, ind);
	i = min_chunk(vars, ind);
	if (max != -1)
		m = sort_bubble(&vars->chunk[ind], max - i);
	while (i < max)
	{
		if ((m == vars->chunk[ind] || (vars->pb[i] > m && m < vars->chunk[ind]))
			&& crescent(vars->pa, vars->len_a) == 0)
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
			order_a(vars);
			i++;
		}
		else if (m < vars->chunk[ind] && (vars->pb[i] < m
				&& vars->pb[i + 1] < m) && m != vars->pb[i + 1] && i + 1 < max)
			ft_swap(vars->pb, 'b');
		i++;
	}
	if (i == 0 && max == -1)
		*v = 1;
}

/*
* Verification of a chunk.
* If the chunk (midpoint) in settings contain only one number return 0.
* Otherwise return 1.
*/

int	alone(int midpoint, t_vars *vars)
{
	int	i;
	int	ic;
	int	j;

	i = 0;
	ic = 0;
	j = 0;
	while (ic < vars->len_c && vars->chunk[ic] != midpoint)
		ic++;
	if (ic == 0 || ic >= vars->len_c)
		return (1);
	// && vars->pb[i] < vars->chunk[ic]
	while (i < vars->len_b)
	{
		if (vars->chunk[ic] > vars->pb[i] && vars->pb[i] >= vars->chunk[ic - 1])
			j++;
		i++;
	}
	if (i - j != 1)
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
		if (r == 0)
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
		else if (r == 1)
			vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
	}
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'b');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
}

/*
* Use to order the A stack when the first element of B stack is
* push on the A stack.
* Each time a new element is push on the stack A, we need to sort this element
* until the next element is biggest than this element.
*/

/*
* [!WARNING]
* We need to setup the value which is sort in nb_sup else we will
* sort infinitely.
* We need to reverse to send the list.
* Previous line are done.
* Maybe i_max is usefull ? Else than for the r variable.
*
* Maybe line 129 len_a -1
*
*/

void	order_a(t_vars *vars)
{
	int	i;
	int	s;

	i = 0;
	if (vars->len_a > 0)
		s = vars->pa[0];
	while (i < vars->len_a - 1 && vars->pa[i] > vars->pa[i + 1])
	{
		if (s > vars->pa[i + 1] && nb_sup(vars, s) > 1)
		{
			ft_swap(vars->pa, 'a');
			ft_rotate(vars->pa, vars->len_a, 'a');
		}
		else if (nb_sup(vars, s) == 1)
			ft_swap(vars->pa, 'a');
		else if (nb_sup(vars, s) == 0)
			break ;
		i++;
	}
	//reverse(vars, i + 1);
}

/*
* For the management of the last chunk.
* Use rrb and rb to sort in a decreasing order.
* After the ordre function we need to swap if it's needed in A stack.
*/

void	special_case(t_vars *vars)
{
	int	i;
	int	j;
	int	mx;
	int	length;

	i = 0;
	length = vars->len_b;
	while (i < length)
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
		order_b(vars, j);
		order_a(vars);
		i++;
	}
}
