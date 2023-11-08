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

static int	ft_charcount(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (!str)
		return (0);
	if (str[i] == c)
	{
		j = 0;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			j++;
		i++;
	}
	return (j);
}

static int	ft_gap(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_substr1(char const *s, char c)
{
	int			len;
	unsigned int		i;
	char				*tab;

	len = ft_gap(s, c);
	i = 0;
	tab = ft_calloc((1 + len), sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i] && s[i] == c)
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**tab;

	i = 0;
	x = 0;
	tab = malloc ((ft_charcount(s, c) + 1) * sizeof(char *));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			tab[x++] = ft_substr1(&s[i], c);
		i++;
	}
	tab[x] = 0;
	return (tab);
}
