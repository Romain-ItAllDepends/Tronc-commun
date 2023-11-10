/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:06:24 by rgobet            #+#    #+#             */
/*   Updated: 2023/10/31 18:23:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		len;
	size_t		i;
	const char	*src;

	if (c > 255)
		c = c % 256;
	i = 0;
	src = s;
	len = ft_strlen(src);
	while (i < n)
	{
		if (src[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
