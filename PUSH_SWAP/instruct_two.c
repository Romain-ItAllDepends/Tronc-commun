/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:09 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/25 16:51:40 by rgobet           ###   ########.fr       */
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
	while (length > i)
	{
		rr[i + 1] = tab[i];
		i++;
	}
	rr[0] = tab[length - 1];
	if (c != 'x')
		ft_printf("rr%c\n", c);
	free(tab);
	return (rr);
}

void	rrr(int **pa, int **pb, int la, int lb)
{
	*pa = ft_reverse_rotate(*pa, la, 'r');
	*pb = ft_reverse_rotate(*pb, lb, 'x');
	return ;
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
