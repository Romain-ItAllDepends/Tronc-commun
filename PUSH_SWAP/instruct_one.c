/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:51 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/18 14:44:51 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Permet de swap les deux premiers nombre de la pile a ou b selon c et la liste en param
int	*ft_swap(int *tab, char c)
{
	int	b;

	b = tab[1];
	tab[1] = tab[0];
	tab[0] = b;
	if (!c == 'x')
		ft_printf("s%c", c);
	return (tab);
}

void	ss(int **pa, int **pb, int la, int lb)
{
	int	temp;

	*pa = ft_swap(*pa, 's');
	*pb = ft_swap(*pb, 'x');
	return ;
}

int	*ft_push(int *tab, int x, int length, char c)
{
	// Prend le premier élément au sommet de b et le met sur a. Et vice versa selon les params.
	//Ne fait rien si b est vide.
	int	i;
	int	*a;

	i = 0;
	a = malloc((length + 1) * sizeof(int));
	if (!a)
		return (NULL);
	while (length >= i)
	{
		if (i == 0)
			a[i] = x;
		if (i > 0)
			a[i] = tab[i + 1];
		i++;
	}
	ft_printf("p%c", c);
	free(tab);
	return (tab);
}

int	*ft_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le haut tous les élements de la pile a ou b.
	//Le premier élément devient le dernier.
	int	temp;

	temp = tab[0];
	tab[0] = tab[length - 1];
	tab[length - 1] = temp;
	if (!c == 'x')
		ft_printf("r%c", c);
	return (tab);
}

void	rr(int **pa, int **pb, int la, int lb)
{
	int	temp;

	*pa = ft_rotate(*pa, la, 'r');
	*pb = ft_rotate(*pb, lb, 'x');
	return ;
}
