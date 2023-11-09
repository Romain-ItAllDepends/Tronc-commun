/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:49:18 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/03 18:37:40 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;

	if (!s)
		return (0);
	i = 0;
	tab = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	return (tab);
}
