/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:40:34 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/03 14:37:11 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_charcount(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && i != 0)
			j++;
		i++;
	}
	if (str[0] != c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		x;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc((ft_charcount(s, c) + ft_strlen1(s)) * sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		if (i == 0 && s[i++] == c)
			j = i;
		if (s[i] == c && s[i + 1] != c)
		{
			tab[x] = ft_substr(s, j, i - j);
			j = i + 1;
			x++;
		}
		i++;
	}
	if (s[i - 1] != c)
		tab[x] = ft_substr(s, j, i - j);
	return (tab);
}
