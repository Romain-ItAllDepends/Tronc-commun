/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:52:41 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/10 07:05:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tab;
	size_t		i;
	long int	size_m;

	size_m = nmemb * size;
	if ((int)size_m < 0 || ((int)size < 0 && (int)nmemb < 0))
		return (NULL);
	i = 0;
	tab = malloc(size_m);
	if (tab == 0)
		return (0);
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
