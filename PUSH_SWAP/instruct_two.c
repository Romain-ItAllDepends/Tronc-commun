/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/13 16:27:54 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_reverse_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le bas tous les élements de la pile a ou b selon les params.
	//Le dernier élément devient le premier.
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
