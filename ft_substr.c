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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*tab;

	i = start;
	tab = malloc((1 + len) * sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i] && len > (i - start))
	{
		tab[i - start] = s[i];
		i++;
	}
	tab[i - start] = '\0';
	return (tab);
}
