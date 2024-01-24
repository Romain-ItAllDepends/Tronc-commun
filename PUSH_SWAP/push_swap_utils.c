/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_fill(int *tab, int length);
int	*ft_switch(int *sort, int j);

int	nb_inf(t_vars *vars, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->len_a)
	{
		if (n > vars->pa[i])
			j++;
		i++;
	}
	return (j);
}

void	ft_split_initb(t_vars *vars)
{
	int			midpoint;
	int			nb;
	int			i;

	i = 0;
	midpoint = sort_bubble(vars->pa, vars->len_a);
	nb = nb_inf(vars, midpoint);
	while (i < 25 && i < nb)
	{
		if (vars->pa[0] < midpoint)
		{
			vars->pb = ft_push(vars->pb, &vars->len_b, vars->pa[0], 'b');
			vars->pa = ft_push_balance(vars->pa, &vars->len_a);
			i++;
		}
		else if (vars->pa[0] >= midpoint && vars->len_a > 1)
			vars->pa = ft_rotate(vars->pa, vars->len_a, 'a');
		if (nb_inf(vars, midpoint) == 0)
			break ;
	}
}

int	sort_bubble(int *tab, int length)
{
	int	*sort;
	int	i;
	int	j;
	int	l;

	i = 0;
	if (length == 0)
		return (0);
	l = length;
	sort = ft_fill(tab, length);
	if (sort == 0)
		return (-1);
	while (i < length)
	{
		j = -1;
		while (j++ < l - 2)
		{
			if (sort[j] > sort[j + 1])
				sort = ft_switch(sort, j);
		}
		l--;
		i++;
	}
	return (select_chunk_size(sort, length));
}

int	*ft_switch(int *sort, int j)
{
	int	temp;

	temp = sort[j + 1];
	sort[j + 1] = sort[j];
	sort[j] = temp;
	return (sort);
}

int	*ft_fill(int *tab, int length)
{
	int	i;
	int	*res;

	res = malloc (length * sizeof(int));
	if (!res)
		return (0);
	i = 0;
	while (i < length)
	{
		res[i] = tab[i];
		i++;
	}
	return (res);
}
