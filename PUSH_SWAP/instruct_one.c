/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:51 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/06 13:51:14 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

// Permet de swap les deux premiers nombre de la pile a ou b selon c et la liste en param.
void	ft_swap(int *tab, char c)
{
	int	b;

	b = tab[1];
	tab[1] = tab[0];
	tab[0] = b;
	if (c != 'x')
		ft_printf("s%c\n", c);
}

void	ss(t_vars *vars)
{
	ft_swap(vars->pa, 's');
	ft_swap(vars->pb, 'x');
	return ;
}

int	*ft_push(int *p, int *length, int n, char c)
{
	// Prend le premier élément au sommet de b et le met sur a. Et vice versa selon les params.
	//Ne fait rien si b est vide.
	int	i;
	int	*pn;

	i = 1;
	*length += 1;
	pn = malloc(*length * sizeof(int));
	if (!pn)
		return (NULL);
	pn[0] = n;
	while (*length > i && *length - 1 > 0)
	{
		pn[i] = p[i - 1];
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

void	rr(t_vars *vars)
{
	vars->pa = ft_rotate(vars->pa, vars->len_a, 'r');
	vars->pb = ft_rotate(vars->pb, vars->len_b, 'x');
}
