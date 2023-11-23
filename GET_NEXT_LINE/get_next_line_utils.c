/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:37:14 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/23 16:46:49 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	tab = malloc((1 + ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	i = 0;
	j = 0;
	if (tab == 0)
		return (0);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	ft_back(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_split(char *line, char *buffer, int count)
{
	char	*tab;
	int	i;

	i = ft_strlen(line) + ft_back(buffer) + 1;
	tab = malloc (i * sizeof(char));
	if (tab == 0)
		return (0);
	i = 0;
	while (tab[i])
	{
		tab[i] = line[i];
		i++;
	}
	i = 0;
	while (tab[i + ft_strlen(line)])
	{
		tab[i + ft_strlen(line)] = buffer[i];
		i++;
	}
	tab[i + ft_strlen(line)] = '\0';
	if (count > 0)
		free(line);
	return (tab);
}

int	ft_read(int fd, char *s)
{
	if(read(fd, s, BUFFER_SIZE) < 0)
		return (0);
	return (1);
}

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
