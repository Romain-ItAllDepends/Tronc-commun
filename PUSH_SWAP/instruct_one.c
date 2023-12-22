/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:51 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/22 15:12:03 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

// Permet de swap les deux premiers nombre de la pile a ou b selon c et la liste en param.
int	*ft_swap(int *tab, char c)
{
	int	b;

	b = tab[1];
	tab[1] = tab[0];
	tab[0] = b;
	if (c != 'x')
		ft_printf("s%c\n", c);
	return (tab);
}

void	ss(int **pa, int **pb)
{
	*pa = ft_swap(*pa, 's');
	*pb = ft_swap(*pb, 'x');
	return ;
}

int	*ft_push(int *p, int *length, int n, char c)
{
	// Prend le premier élément au sommet de b et le met sur a. Et vice versa selon les params.
	//Ne fait rien si b est vide.
	int	i;
	int	*pn;

	i = 0;
	*length += 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	while (*length > i)
	{
		if (i == 0)
			pn[i] = n;
		else
			pn[i] = p[i];
		i++;
	}
	ft_printf("p%c\n", c);
	free(p);
	return (pn);
}

int	*ft_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le haut tous les élements de la pile a ou b.
	//Le premier élément devient le dernier.
	int	temp;
	int	i;

	i = 0;
	while (i < length)
	{
		temp = tab[i];
		tab[i] = tab[length - i - 1];
		tab[length - i - 1] = temp;
		i++;
	}
	if (c != 'x')
		ft_printf("r%c\n", c);
	return (tab);
}

void	rr(int **pa, int **pb, int la, int lb)
{
	*pa = ft_rotate(*pa, la, 'r');
	*pb = ft_rotate(*pb, lb, 'x');
	return ;
}
