/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_reverse_rotate(int *tab, int length, char c)
{
	int	*rr;
	int	i;

	i = 0;
	rr = malloc (length * sizeof(int));
	if (!rr)
		return (NULL);
	rr[0] = tab[length - 1];
	while (length - 1 > i)
	{
		rr[i + 1] = tab[i];
		i++;
	}
	if (c != 'x')
		ft_printf("rr%c\n", c);
	free(tab);
	return (rr);
}

void	rrr(t_vars *vars)
{
	vars->pa = ft_reverse_rotate(vars->pa, vars->len_a, 'r');
	vars->pb = ft_reverse_rotate(vars->pb, vars->len_b, 'x');
}

int	*ft_push_balance(int *p, int *length)
{
	int	i;
	int	*pn;

	*length -= 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	i = 0;
	while (*length > i)
	{
		pn[i] = p[i + 1];
		i++;
	}
	free(p);
	return (pn);
}

int	nb_min(int *p, int length)
{
	int	i;
	int	nb;

	i = 1;
	nb = p[0];
	while (i < length)
	{
		if (nb > p[i])
			nb = p[i];
		i++;
	}
	return (nb);
}

int	nb_max(int *p, int length)
{
	int	i;
	int	nb;

	i = 1;
	nb = p[0];
	while (i < length)
	{
		if (nb < p[i])
			nb = p[i];
		i++;
	}
	return (nb);
}
