/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_hundred.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 08:38:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/27 14:17:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_chunk_setup(t_vars *vars);
static int	first(t_vars *vars, int chunk);

int	verif_and_push(t_vars *vars, int i)
{
	while (1)
	{
		if (i > vars->len_b / 2)
		{
			vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'b');
			i++;
		}
		else if (i != 0)
		{
			vars->pb = ft_rotate(vars->pb, vars->len_b, 'b');
			i--;
		}
		if (i == 0 || i == vars->len_b)
		{
			vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
			vars->pb = ft_push_balance(vars->pb, &vars->len_b);
			i = 0;
			return (i);
		}
	}
	return (i);
}

void	ft_one_hundred(t_vars *vars)
{
	int	n;
	int	i;

	i = 0;
	ft_chunk_setup(vars);
	while (vars->len_b != 0)
	{
		n = nb_max(vars->pb, vars->len_b);
		while (vars->pb[i] != n)
			i++;
		i = verif_and_push(vars, i);
		if (i != 0)
			exit(1);
	}
	free(vars->pb);
}

static int	first(t_vars *vars, int chunk)
{
	int	i;
	int	j;

	i = 0;
	while (vars->pa[i] > chunk)
		i++;
	j = vars->len_a - 1;
	while (vars->pa[j] > chunk)
		j--;
	if (i < (vars->len_a - j))
		return (i);
	else
		return (j);
}

static void	reverse_rotate_case(t_vars *vars, int x, int nb)
{
	while (x++ != (vars->len_a - nb))
		vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
}

static void	ft_chunk_setup(t_vars *vars)
{
	int	i;
	int	x;
	int	nb;

	i = 20;
	while (vars->len_a != 1)
	{
		x = 0;
		if (nb_inf(vars, i) == 0 || nb_inf(vars, i) > 20)
			i = sort(vars->pa, vars->len_a);
		nb = first(vars, i);
		if (nb < vars->len_a / 2)
		{
			while (x++ != nb)
				vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
			vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
			vars->pa = ft_push_balance(vars->pa, &vars->len_a);
		}
		else
			reverse_rotate_case(vars, x, nb);
	}
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
}
