/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:24:10 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/23 13:25:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_charcount(char const *str, char c)
{
	int	i;
	int	j;

	if (!str[0])
		return (0);
	i = 0;
	j = 1;
	if (str[i] == c || str[ft_strlen(str) - 1] == c)
	{
		j = 0;
		if (str[ft_strlen(str) - 1] != c)
			j = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			j++;
		i++;
	}
	if (j == i)
		return (0);
	return (j);
}

static int	ft_strlendb(char **s, int length)
{
	int	i;
	int	x;
	int	n;
	int	sp;

	i = 0;
	n = 1;
	sp = 0;
	while (n < length)
	{
		x = 0;
		while (s[n][x])
		{
			if (s[n][x + 1] == 0)
				sp++;
			x++;
		}
		n++;
		i += x;
	}
	return (i + sp);
}

static int	ft_substr(char const *s, int *tabl, char *str, t_vars *vars)
{
	char			c;
	unsigned int	i;
	int				tab;

	i = 0;
	tab = 0;
	c = ' ';
	error_isnt_int((char *)s, tabl, str, vars);
	while (s[i] && s[i] != c)
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		tab = tab * 10 + (s[i] - '0');
		i++;
	}
	if (s[0] == '-')
		return (tab * -1);
	return (tab);
}

int	*conversion_char_to_int_array(char const *s, char c, int *length,
	t_vars *vars)
{
	int	i;
	int	x;
	int	*tab;

	i = 0;
	x = 0;
	if (!s)
		return (0);
	*length = ft_charcount(s, c);
	tab = malloc(*length * sizeof(int));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			tab[x++] = ft_substr(&s[i], tab, (char *)s, vars);
		while (s[i] && s[i] != c)
			i++;
	}
	return (tab);
}

char	*ft_strjoin(char **s, int nbList, t_vars *vars)
{
	char	*tab;
	int		i;
	int		j;
	int		x;

	error_no_number(s, nbList, vars);
	tab = malloc((ft_strlendb(s, nbList) + 1) * sizeof(char));
	i = 0;
	j = 1;
	if (tab == 0)
		return (0);
	while (j < nbList)
	{
		tab[i++] = ' ';
		x = 0;
		while (s[j][x])
		{
			tab[i] = s[j][x];
			i++;
			x++;
		}
		j++;
	}
	tab[i] = 0;
	return (tab);
}
