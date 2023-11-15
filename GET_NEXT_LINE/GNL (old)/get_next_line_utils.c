/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:38:09 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/11 16:16:49 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_mod(char *str)
{
	int	i;
	int	count;
	int	n;

	i = 0;
	count = 0;
	n = 0;
	while (str[i])
	{
		if (n == 0 && str[i] != '\n')
			count++;
		else
			n++;
		i++;
	}
	return (count);
}

int	ft_gap(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_substr_mod(char const *s, char c)
{
	unsigned int	i;
	char			*tab;
	int				len;

	len = ft_gap(s, c);
	i = 0;
	tab = malloc((1 + len) * sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i] && s[i] != c)
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}

static char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	tab = ft_calloc(ft_strlen_mod(s) + 1, sizeof(char));
	if (tab == 0)
		return (0);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}

char	*ft_keep_file(int fd)
{
	int	i;
	int	n;
	char	*line;

	i = 1;
	n = fd;
	n = read(n, line[0], 1);
		if (n == -1)
			return (0);
	while (line[i] != '\n' || line[i] != '\0')
	{
		n = read(n, line[i], 1);
		if (n == -1)
			return (0);
	}
	close(n);
	return (line);
}
