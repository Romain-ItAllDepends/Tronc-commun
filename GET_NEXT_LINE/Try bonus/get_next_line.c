/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:56:32 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/11 14:26:12 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	*finish(char *s)
{
	if (s[0] == 0)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	char		*stash;
	static char	buffer[BUFFER_SIZE + 1];
	//static int	count;
	int			n;

	stash = NULL;
	n = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (buffer[0] != 0)
		stash = ft_strjoin(buffer, stash, n);
	while (1)
	{
		if (ft_strchr(stash, '\n') == 0)
		{
			n = read(fd, buffer, BUFFER_SIZE);
			buffer[n] = 0;
			if (n < 0)
				return (NULL);
			stash = ft_strjoin(buffer, stash, n);
		}
		if (ft_strchr(stash, '\n') > 0)
			return (cut(stash, buffer));
		else if (n == 0)
			return (finish(stash));
	}
	return (0);
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
