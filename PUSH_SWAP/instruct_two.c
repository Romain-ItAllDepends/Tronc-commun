/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/02 11:13:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ft_reverse_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le bas tous les élements de la pile a ou b selon les params.
	//Le dernier élément devient le premier.
	int	*rr;
	int	i;

	i = 0;
	rr = malloc (length * sizeof(int));
	if (!rr)
		return ;
	while (length > i)
	{
		rr[i + 1] = tab[i];
		i++;
	}
	rr[0] = tab[length - 1];
	if (c != 'x')
		ft_printf("rr%c\n", c);
	free(tab);
	tab = rr;
}

void	rrr(t_vars *vars)
{
	ft_reverse_rotate(vars->pa, vars->len_a, 'r');
	ft_reverse_rotate(vars->pb, vars->len_b, 'x');
}

void	ft_push_balance(int *p, int *length)
{
	int	i;
	int	*pn;

	*length -= 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return ;
	i = 0;
	while (*length > i)
	{
		pn[i] = p[i + 1];
		i++;
	}
	free(p);
	p = pn;
}
