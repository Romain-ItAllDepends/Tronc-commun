/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:28 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/28 12:42:58 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*chunk_init(int	*chunk, int newmidpoint)
{
	static int	length;
	int	*newchunk;
	int	i;

	length++;
	newchunk = malloc (sizeof(int) * length);
	i = 0;
	while (chunk && i < length - 1)
	{
		newchunk[i] = chunk[i];
		i++;
	}
	while (i < length)
	{
		newchunk[i] = newmidpoint;
		i++;
	}
	free(chunk);
	return (newchunk);
}
