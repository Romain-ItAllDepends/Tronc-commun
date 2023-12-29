/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/29 11:12:00 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

/*
int	*sort(int *pa, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (pa[i] < min)
		{
			min = pa[i];
			while (pa[0] != min)
				pa = ft_reverse_rotate(pa, length, 'a');
		}
		i++;
	}
	return (pa);
}
*/

int	*core(int *pa, int *lengtha)
{
	int	*pb;
	int	**chunk;
	int	lengthb;
	int	lengthc;
	int	i;

	i = 0;
	lengthb = 0;
	lengthc = 0;
	pb = NULL;
	chunk = NULL;
	while (*lengtha > 2 || decreasing(pa, *lengtha) == 1)
	{
		lengthc++;
		chunk = chunk_init(sort_bubble(pa, *lengtha), pa, chunk);
		if (!chunk)
			exit(1);
		ft_split_initb(&pa, &pb, lengtha, &lengthb);
		i++;
	}
	while (lengthb != 0 || decreasing(pb, lengthb) == 1)
		ft_split_inita(&pb, &pa, lengtha, &lengthb);
	free(pb);
	ft_free(chunk, lengthc);
	return (pa);
}

//Gestion d'erreur pas de doublon peut recup le midpoint avant le split init

int	main(int ac, char **av)
{
	char	*full_char;
	int		*tab;
	int		*result;
	int		length;
	int		i;

	i = 0;
	if (ac == 1)
		exit(0);
	full_char = ft_strjoin(av, ac);
	tab = conversion_char_to_int_array(full_char, ' ', &length);
	free(full_char);
	error_duplication(tab, length);
	result = core(tab, &length);
	while (i < length)
	{
		ft_printf("%d\n", result[i]);
		i++;
	}
	ft_printf("%d", length);
	free(result);
	return (0);
}
