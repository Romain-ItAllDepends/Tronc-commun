/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/19 14:57:16 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_split_init(int **pa, int *length, char c)
{
	int	*pb;
	int	i;

	pb = malloc((*length / 2) * sizeof(int));
	if (!pa)
		return (NULL);
	*length -= *length / 2;
	i = 0;
	while (i < length + 1)
	{
		ft_push(pa, &p, length, c);
		i++;
	}
	*pa = ft_split(pa, length, 1);
	return (pb);
}
