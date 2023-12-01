/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:28:48 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/01 17:38:54 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"
// Add une verif /n en option
int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
// Supp
int	ft_back(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}
// Supp
void	ft_clear(char *s, char *buffer)
{
	int	i;

	i = 0;
	if (s)
		free(s);
	s = malloc(ft_strlen(&buffer[ft_back(buffer)]) * sizeof(char));
	if (s == 0)
		return ;
	while (s[i])
	{
		s[i] = 0;
		i++;
	}
}

char	*ft_fill(char *line, char *buffer, char *tab)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			tab[i] = line[i];
			i++;
		}
		i = 0;
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		tab[i + ft_strlen(line)] = buffer[i];
		i++;
	}
	tab[i + ft_strlen(line)] = '\0';
	return (tab);
}

char	*ft_split(char *stash, char *buffer)
{
	char	*tab;
	int		i;

	i = (ft_strlen(stash) + ft_back(buffer)) + 1;
	tab = malloc(i * sizeof(char));
	if (tab == 0)
		return (0);
	tab = ft_fill(stash, buffer, tab);
	if (stash != 0)
		free(stash);
	return (tab);
}


