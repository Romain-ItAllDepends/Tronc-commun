/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:18 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/07 11:39:13 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	ft_strlen(char *s, int opt)
{
	int	i;

	if (!s || s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (opt >= 1 && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_split(char *stash, char *buffer)
{
	char	*tab;
	int		i;

	i = (ft_strlen(stash, 0) + ft_strlen(buffer, 1)) + 2;
	tab = malloc(i * sizeof(char));
	if (tab == 0)
		return (0);
	i = 0;
	while (stash && stash[i])
	{
		tab[i] = stash[i];
		i++;
	}
	while (buffer[ft_strlen(buffer, 2) - i])
	{
		tab[i] = buffer[i - ft_strlen(stash, 0)];
		i++;
	}
	tab[i] = '\0';
	if (stash && ft_strlen(stash, 1) == 0)
		free(stash);
	if (stash && ft_strlen(stash, 1) == 0)
		stash = NULL;
	return (tab);
}

char	*ft_join(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s, 0) + BUFFER_SIZE) + 2);
	if (tab == 0)
		return (NULL);
	while (s && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	while (b[j])
	{
		tab[i++] = b[j];
		b[j++] = 0;
	}
	tab[i] = 0;
	if (s || (s && s[0] == '\0'))
		free(s);
	if (s || (s && s[0] == '\0'))
		s = NULL;
	return (tab);
}

int	ft_read(int fd, char *buffer, char *stash)
{
	int	n;

	n = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	if (n == -1 || (n == 0 && (stash && stash[0] == '\0')))
		return (0);
	else if (n == 0)
	{
		if (stash || (stash && stash[0] == '\0'))
			free(stash);
		stash = NULL;
		return (-8);
	}
	return (n);
}
