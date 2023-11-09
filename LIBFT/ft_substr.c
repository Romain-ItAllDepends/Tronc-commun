/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:59:36 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/02 16:35:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_toomuch(const char *s, size_t len)
{
	if (len > ft_strlen(s))
		return (ft_strlen(s));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	i = start;
	len = ft_toomuch(s, len);
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		tab = ft_calloc(1, sizeof(char));
		if (tab == 0)
			return (0);
	}
	else
	{
		tab = ft_calloc((1 + len), sizeof(char));
		if (tab == 0)
			return (0);
		while (s[i] && len > (i - start))
		{
			tab[i - start] = s[i];
			i++;
		}
	}
	return (tab);
}
