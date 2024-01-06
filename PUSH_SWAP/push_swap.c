/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 13:09:25 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
int	*sort(int *pa, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (pa[i] < min)
		{
			min = pa[i];
			while (pa[0] != min)
				pa = ft_reverse_rotate(pa, length, 'a');
		}
		i++;
	}
	return (pa);                                                                                   
}
*/
// while (lengthb != 0 || decreasing(pb, lengthb) == 1)
// 	ft_split_inita(&pb, &pa, lengtha, &lengthb);
t_vars	*core(t_vars *vars)
{
	int	i;

	i = 0;
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
		i++;
	}
	if (crescent(vars->pa, vars->len_a) == 1 && vars->len_b > 0)
	{
		if (vars->len_a == 2 && vars->pa[0] > vars->pa[1])
			ft_swap(vars->pa, 'a');
		reverse_split(vars);
	}
	// i = 0;
	// while (i < vars->len_c)
	// {
	// 	ft_printf("\n%d\n", vars->chunk[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	free(vars->pb);
	free(vars->chunk);
	return (vars);
}

/*
* The instruct_one.c and instruct_two.c are verified !
* Actually making the algorithm.
*/

int	main(int ac, char **av)
{
	t_vars	*vars;
	char	*full_char;
	int		i;

	i = 0;
	if (ac == 1)
		exit(0);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	full_char = ft_strjoin(av, ac);
	vars->pa = conversion_char_to_int_array(full_char, ' ', &vars->len_a);
	free(full_char);
	error_duplication(vars->pa, vars->len_a);
	vars = core(vars);
	while (i < vars->len_a)
	{
		ft_printf("%d\n", vars->pa[i]);
		i++;
	}
	ft_printf("\n%d", vars->len_a);
	free(vars->pa);
	free(vars);
	return (0);
}
