/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/29 17:23:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	s;
	void			*ptr;

	s = nmemb * size;
	if (s < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(s);
	if (ptr)
		ft_memset(ptr, 0, s);
	return (ptr);
}

