/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:35:29 by rgobet            #+#    #+#             */
/*   Updated: 2023/10/31 15:06:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	res;
	size_t	length_d;
	size_t	length_s;

	length_s = ft_strlen(src);
	res = length_s + n;
	if (n != 0)
	{
		length_d = ft_strlen(dest);
		i = 0;
		if (res >= length_s + length_d)
			res = (res - n) + length_d;
		while (length_d + i < (n - 1))
		{
			dest[length_d + i] = src [i];
			i++;
		}
		if (n > length_d)
			dest[length_d + i] = '\0';
	}
	return (res);
}
