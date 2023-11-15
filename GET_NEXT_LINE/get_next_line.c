/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/15 12:05:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_swap(char *buffer, char *stash)
{
	static int	i;
	int			j;

	j = 0;
	while (buffer[j])
	{
		stash[i] = buffer[j];
		i++;
	}
	return (stash);
}

int	ft_read(int fd, char *buffer)
{
	if (read (fd, buffer, BUFFER_SIZE) < 0)
		return (0);
	return (n);
}

char	*get_next_line(int fd)
{
	int			i;
	int			length;
	char		*line;
	char		*buffer[BUFFER_SIZE];
	static char	*stash;

	i = 0;
	while (stash[i] != '\n')
	{
		if (0 == (BUFFER_SIZE % i))
		{
			ft_malloc(stash, i);
			ft_swap(buffer, stash);
		}
		if (stash != '\n')
			free(stash);
		i++;
	}
	stash[i] = '\0';
	line = malloc((ft_strlen(stash) + 1) * sizeof(char));
	if (line == 0)
		return (0);
	line = ft_substr(stash, 0, ft_strlen(stash));
	length = ft_moveptr(stash);
	stash = &stash[ft_moveptr(stash)];
	return (line);
}
