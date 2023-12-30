/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_split_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:43:55 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/30 13:51:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ft_chunk_check(int **pa, int **pb, int ***chunk)
{
	int			i;
	int			j;
	static int	index_midpoint = i + 1;

	j = 0;
	i = chunk[0][0] - 2;
	index_midpoint--;
	while (i > 0)
	{
		while (j < chunk[chunk[0][0]][1])
		{

			j++;
		}
		i--;
	}
}
