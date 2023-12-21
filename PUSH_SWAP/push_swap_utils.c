/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:19:40 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/20 13:44:18 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*ft_split_init(int **pa, int *lengtha, int *lengthb)
{
	int	*pb;
	int	i;

	i = 0;
	pb = NULL;
	while (i < (*lengtha / 2))
	{
		pb = ft_push(pb, lengthb, *pa[0], 'b');
		*pa = ft_push_balance(*pa, lengtha);
		i++;
	}
	return ((int *)pb);
}
