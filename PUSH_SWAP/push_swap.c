/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/20 10:51:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int ft_min(int *p, int length)
{
	int	min;
	int	index;
	int	i;

	i = 0;
	min = p[i];
	while (i < length)
	{
		if (min > p[i])
		{
			min = p[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	*sort(int *pa, int length)
{
	int	min;
	int	i;

	min = ft_min(pa, length);
	i = 0;
	while (min != 0)
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

int	*core(int *pa, int length)
{
	int	*pb;

	pb = ft_split_init(&pa, &length, 'b');
	pa = sort(pa, length);
	pb = sort(pb, length);
	return (pa);
}

int	main(int ac, char **av)
{
	char	*full_char;
	int		*tab;
	int		*result;
	int		length;
	int		i;

	i = 0;
	full_char = ft_strjoin(av, ac);
	tab = conversion_char_to_int_array(full_char, ' ', &length);
	result = core(tab, length);
	while (i < length)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	ft_printf("%d", length);
	free(tab);
	free(full_char);
	return (0);
}
