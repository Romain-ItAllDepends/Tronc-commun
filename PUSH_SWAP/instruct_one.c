/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:51 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/26 11:31:28 by rgobet           ###   ########.fr       */
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

	i = -1;
	*length += 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	while (*length - 1 > i++ && *length > 0)
	{
		if (i == 0)
			pn[i] = n;
		else if (p)
			pn[i] = p[i - 1];
	}
	ft_printf("p%c\n", c);
	if (p != NULL)
		free(p);
	return (pn);
}

int	*ft_rotate(int *tab, int length, char c)
{
	//Décale d’une position vers le haut tous les élements de la pile a ou b.
	//Le premier élément devient le dernier.
	//Exemple 6, 5, 8 -> 5, 8, 6
	int	*res;
	int	i;

	i = 0;
	//ft_printf("\n\n\n\n\n\n\nl %d\n\n\n\n\n\n", length);
	res = malloc (length * sizeof(int));
	if (!res)
		return (NULL);
	while ((i + 1) < length)
	{
		res[i] = tab[i + 1];
		i++;
	}
	//ft_printf("\n\n\n\n\n\n\ni %d\n\n\n\n\n\n", i);
	res[i] = tab[0];
	if (c != 'x')
		ft_printf("r%c\n", c);
	free(tab);
	return (res);
}

void	rr(int **pa, int **pb, int la, int lb)
{
	*pa = ft_rotate(*pa, la, 'r');
	*pb = ft_rotate(*pb, lb, 'x');
	return ;
}
