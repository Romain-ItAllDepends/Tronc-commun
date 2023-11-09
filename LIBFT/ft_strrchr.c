/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:04:00 by rgobet            #+#    #+#             */
/*   Updated: 2023/10/31 17:12:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen1(s);
	if (c == '\0')
		return ((char *)(s + length));
	while ((length - i) >= 0)
	{
		if (s[length - i] == c)
			return ((char *)(s + (length - i)));
		i++;
	}
	return (0);
}
