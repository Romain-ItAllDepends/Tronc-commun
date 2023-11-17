/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:52 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/16 13:44:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_mod(char const *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i + 1);
}

void	ft_join(char *buffer, char *stash)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		stash[i] = buffer[i];
		i++;
	}
}

static size_t	ft_min(const char *s, size_t len)
{
	if ((int)len > ft_strlen(s))
		return (ft_strlen(s));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	i = start;
	if (!s)
		return (0);
	if ((int)start >= ft_strlen(s))
	{
		tab = malloc(1 * sizeof(char));
		if (tab == 0)
			return (0);
	}
	else
	{
		len = ft_min(&s[start], len);
		tab = malloc((1 + len) * sizeof(char));
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