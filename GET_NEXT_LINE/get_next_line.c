/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:56:32 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/07 16:41:55 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_core(int fd, char *stash, char *buffer, char *new_line)
{
	int	n;

	while (ft_strchr(stash, '\n') == 0)
	{
		n = ft_read(fd, buffer, stash);
		if (n == -8)
		{
			new_line = ft_split(stash, buffer);
			free(buffer);
			return (new_line);
		}
		else if (n == 0)
			return (NULL);
		stash = ft_join(stash, buffer);
	}
	if (ft_strchr(stash, '\n') > 0)
	{
		free(buffer);
		buffer = NULL;
		new_line = ft_split(buffer, stash);
		stash = ft_join_d(buffer, &stash[ft_strchr(stash, '\n')]);
	}
	else
	{
		new_line = ft_split(stash, buffer);
		stash = ft_join(stash, &buffer[ft_strchr(buffer, '\n')]);
	}
	if (buffer)
		free(buffer);
	free(stash);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;
	char		*buffer;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	new_line = NULL;
	stash = NULL;
	new_line = ft_core(fd, stash, buffer, new_line);
	return (new_line);
}

#include <stdio.h>

int	main(void)
{
	char	*tab;
	int		fd;
	int		i;

	i = 0;
	fd = open("files/full_nl", O_RDWR);
	while (i < 1)
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
