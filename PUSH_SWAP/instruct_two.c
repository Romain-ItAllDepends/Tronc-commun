/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:09 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/20 11:02:57 by rgobet           ###   ########.fr       */
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
		ft_printf("rr%c", c);
	free(tab);
	return (tab);
}

void	rrr(int **pa, int **pb, int la, int lb)
{
	*pa = ft_reverse_rotate(*pa, la, 'r');
	*pb = ft_reverse_rotate(*pb, lb, 'x');
	return ;
}
