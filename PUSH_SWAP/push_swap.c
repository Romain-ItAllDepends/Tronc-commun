/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/02 11:13:51 by rgobet           ###   ########.fr       */
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
	vars->pb = NULL;
	vars->chunk = NULL;
	while (vars->len_a > 2 || decreasing(vars->pa, vars->len_a) == 1)
	{
		//chunk = chunk_init(sort_bubble(vars->pa, vars->len_a), vars);
		//if (!chunk)
		//	exit(1);
		ft_split_initb(vars);
		i++;
	}
	free(vars->pb);
	ft_free(vars->chunk, vars->len_c / 2);
	return (vars);
}

//Gestion d'erreur pas de doublon peut recup le midpoint avant le split init

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
	//vars->pa = core(vars);
	while (i < vars->len_a)
	{
		ft_printf("%d\n", vars->pa[i]);
		i++;
	}
	ft_printf("%d", vars->len_a);
	free(vars->pa);
	free(vars);
	return (0);
}
