/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:51 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/20 11:01:46 by rgobet           ###   ########.fr       */
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
		ft_printf("s%c", c);
	return (tab);
}

void	ss(int **pa, int **pb)
{
	*pa = ft_swap(*pa, 's');
	*pb = ft_swap(*pb, 'x');
	return ;
}

void	ft_push(int **pa, int **pb, int *length, char c)
{
	// Prend le premier élément au sommet de b et le met sur a. Et vice versa selon les params.
	//Ne fait rien si b est vide.
	int	i;
	int	*p;

	i = 0;
	if (c == 'x')
		length -= 2;
	p = malloc((*length + 1) * sizeof(int));
	if (!p)
		return ;
	while (*length > i)
	{
		if (i == 0 && c == 'x')
			p[i] = *pb[0];
		if (i > 0)
			p[i] = *pb[i + 1];
		i++;
	}
	if (c != 'x')
		ft_printf("p%c", c);
	if (c == 'x')
		free(pa);
	if (c != 'x')
		ft_push(pb, pa, length, 'x');
	return ;
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
		ft_printf("r%c", c);
	return (tab);
}

void	rr(int **pa, int **pb, int la, int lb)
{
	*pa = ft_rotate(*pa, la, 'r');
	*pb = ft_rotate(*pb, lb, 'x');
	return ;
}
