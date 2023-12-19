/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:07:53 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/19 14:18:35 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int min(*p, int length)
{
	int	min;
	int	index;
	int	i;

	i = 0;
	min = tab[i];
	while (i < length)
	{
		if (min > tab[i])
		{
			min = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	*sort(int *pa, int length)
{
	int	min;

	min = min(pa, length);
	while (min != 0)
	{
		
	}
}

int	*core(int *pa, int length)
{
	char	*pb;

	pb = malloc(1 * sizeof(int));
	if (!pb)
		return (NULL);
	pb[0] = 0;
	
}

int	main(int ac, char **av)
{
	char	*full_char;
	int		*tab;
	int		length;

	full_char = ft_strjoin(av, ac);
	tab = conversion_char_to_int_array(full_char, ' ', &length);
	return (0);
}
