/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/27 10:46:37 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars	*core(t_vars *vars)
{
	vars->len_b = 0;
	vars->len_c = 0;
	vars->pb = NULL;
	vars->chunk = NULL;
	while (vars->len_a > 2 && crescent(vars->pa, vars->len_a) == 1)
	{
		vars->chunk = chunk_init(sort_bubble(vars->pa, vars->len_a), vars);
		if (!vars->chunk)
			exit(1);
		ft_split_initb(vars);
	}
	if (vars->len_b > 0)
	{
		if (vars->len_a == 2 && vars->pa[0] > vars->pa[1]
			&& vars->len_b >= 2 && vars->pb[0] < vars->pb[1])
			ss(vars);
		else if (vars->len_a == 2 && vars->pa[0] > vars->pa[1])
			ft_swap(vars->pa, 'a');
		if (!(crescent(vars->pa, vars->len_a) == 0 && vars->len_b == 0))
			reverse_split(vars);
	}
	free(vars->pb);
	free(vars->chunk);
	return (vars);
}

void	ft_three(t_vars *vars)
{
	vars->np = normalisation(vars->pa, vars->len_a);
	if (vars->np[0] == 1 && vars->np[1] == 0)
		ft_swap(vars->pa, 'a');
	else if (vars->np[0] == 2 && vars->np[1] == 1)
	{
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
		ft_swap(vars->pa, 'a');
	}
	else if (vars->np[0] == 2 && vars->np[1] == 0)
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	else if (vars->np[0] == 0 && vars->np[1] == 2)
	{
		ft_swap(vars->pa, 'a');
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	}
	else if (vars->np[0] == 1 && vars->np[1] == 2)
		vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'a');
	free(vars->np);
}

void	ft_five(t_vars *vars)
{
	while (vars->pa[0] != nb_min(vars->pa, vars->len_a))
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	while (vars->pa[0] != nb_max(vars->pa, vars->len_a))
		vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
	vars->pa = ft_push_balance(vars->pa, &vars->len_a);
	ft_three(vars);
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
	vars->pa = ft_push(vars->pa, &vars->len_a, vars->pb[0], 'a');
	vars->pb = ft_push_balance(vars->pb, &vars->len_b);
	free(vars->pb);
}

t_vars	*ft_sort_choice(t_vars *vars)
{
	if (vars->len_a == 2)
		ft_swap(vars->pa, 'a');
	if (vars->len_a == 3)
		ft_three(vars);
	if (vars->len_a == 4)
		ft_four(vars);
	if (vars->len_a == 5)
		ft_five(vars);
	if (vars->len_a > 5 && vars->len_a <= 100)
		ft_one_hundred(vars);
	else
		vars = core(vars);
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	char	*full_char;

	if (ac == 1)
		exit(1);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	full_char = ft_strjoin(av, ac, vars);
	vars->pa = conversion_char_to_int_array(full_char, ' ', &vars->len_a, vars);
	free(full_char);
	error_duplication(vars->pa, vars->len_a, vars);
	if (crescent(vars->pa, vars->len_a) == 1)
		vars = ft_sort_choice(vars);
	free(vars->pa);
	free(vars);
	return (0);
}
