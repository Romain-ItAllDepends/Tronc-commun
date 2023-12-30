/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:26:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/30 14:33:26 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	*copy_tab(int *old_chunk)
{
	int	*new_chunk;

	new_chunk = malloc(sizeof(int) * 3);
	new_chunk[0] = chunk[0];
	new_chunk[1] = chunk[1];
	new_chunk[2] = chunk[2];
	return (new_chunk);
}