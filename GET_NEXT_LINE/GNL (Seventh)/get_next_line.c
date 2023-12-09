/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:56:32 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/08 16:58:01 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 1 && s[0] == '\n')
		tab = malloc (1);
	else
		tab = malloc ((ft_strlen(s) + 1) * sizeof(char));
	// Probleme si "\n" le malloc fait 2
	if (tab == 0)
		return (0);
	while (s[i] != '\n')
		i++;
	i++;
	while (s[i])
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = 0;
	free(s);
	s = NULL;
	return (tab);
}

char	*ft_core(int fd, char **stash, char *buffer, char *new_line)
{
	int	n;

	while (ft_strchr(*stash, '\n') == 0 || ft_strchr(*stash, '\n') == -1)
	{
		n = ft_read(fd, buffer, *stash);
		if (n == -8)
		{
			new_line = ft_split(*stash, buffer);
			free(buffer);
			return (new_line);
		}
		else if (n == 0)
			return (NULL);
		*stash = ft_join(*stash, buffer);
	}
	if (ft_strchr(*stash, '\n') > 0)
	{
		ft_free(buffer);
		new_line = ft_split(buffer, *stash);
		*stash = ft_join_d(buffer, ft_strdup(*stash));
	}
	else
	{
		new_line = ft_split(*stash, buffer);
		*stash = ft_join(*stash, &buffer[ft_strchr(buffer, '\n')]);
	}
	if (buffer)
		free(buffer);
	if (*stash[0] == '\0')
		ft_free(*stash);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;
	char		*buffer;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	buffer[0] = 0;
	new_line = NULL;
	new_line = ft_core(fd, &stash, buffer, new_line);
	return (new_line);
}

#include <stdio.h>

int	main(void)
{
	char	*tab;
	int		fd;
	int		i;

	i = 0;
	fd = open("files/41_no_nl", O_RDWR);
	while (i <= 10)
	{
		tab = get_next_line(fd);
		printf("%s", tab);
		i++;
		if (tab)
			free(tab);
	}
	close(fd);
	return (0);
}