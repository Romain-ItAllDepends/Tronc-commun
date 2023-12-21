/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/21 13:46:02 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

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

int	*core(int *pa, int lengtha)
{
	int	*pb;
	int	lengthb;

	lengthb = 0;
	while (ft_strlen(pa) != 2)
		ft_split_init(&pa, &pb, lengtha, &lengthb);
	while (ft_strlen(pb) != 2)
		ft_split_inita(&pb, &pa, &lengtha, &lengthb);
	pa = sort(pa, *lengtha);
	pb = sort(pb, lengthb);
	free(pb);
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
		ft_printf("%d %d\n", tab[i], i);
		i++;
	}
	ft_printf("%d", length);
	free(tab);
	free(full_char);
	return (0);
}
