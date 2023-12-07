/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:56:32 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/07 11:37:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_core(int fd, char *stash, char *buffer, char *new_line, int n)
{
	while (1)
	{
		if (new_line)
			free(new_line);
		if (ft_strlen(stash, 1) == 0)
			n = ft_read(fd, buffer, stash);
		if (n == -8)
		{
			new_line = ft_split(stash, buffer);
			return (new_line);
		}
		else if (n == 0)
			return (NULL);
		stash = ft_join(stash, buffer);
		if (ft_strlen(stash, 1) > 0)
		{
			new_line = ft_split(stash, buffer);
			stash = ft_join(stash, &buffer[ft_strlen(buffer, 1) + 1]);
			return (new_line);
		}
		else if (ft_strlen(stash, 1) == 0)
			stash = ft_join(stash, buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*new_line;
	char		buffer[BUFFER_SIZE + 1];
	int			n;
/*
	n = ft_read(fd, buffer, stash);
	if (n == -8)
	{
		new_line = ft_split(stash, buffer);
		return (new_line);
	}
	else if (n == 0)
		return (NULL);
	stash = NULL;
	stash = ft_join(stash, buffer);
	new_line = NULL;
	if (ft_strlen(stash, 1) > 0)
	{
		new_line = ft_split(stash, buffer);
		free(stash);
		stash = ft_join(NULL, &buffer[ft_strlen(buffer, 1) + 1]);
	}
	else*/
	new_line = NULL;
	n = 0;
	new_line = ft_core(fd, stash, buffer, new_line, n);
	return (new_line);
}

#include <stdio.h>

int	main(void)
{
	char	*tab;
	int		fd;
	int		i;

	i = 0;
	fd = open("files/empty", O_RDWR);
	while (i < 2)
	{
		tab = get_next_line(fd);
		if (tab)
			printf("%s", tab);
		i++;
		free(tab);
	}
	close(fd);
	return (0);
}