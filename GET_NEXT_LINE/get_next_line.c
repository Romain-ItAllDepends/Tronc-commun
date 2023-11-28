/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:25:49 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/28 15:09:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *s, char *b, int count)
{
	int	i;
	int	j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s) + ft_strlen(b)) * sizeof(char));
	if (tab == 0)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			tab[i] = s[i];
			i++;
		}
	}
	while (b[j])
	{
		tab[i] = b[j];
		i++;
		j++;
	}
	tab[i] = 0;
	if (count > 0)
		free(s);
	return (tab);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char	*new_line;
	char	buffer[BUFFER_SIZE + 1];
	static int	count;
	int	n;


	if (fd == 0)
		return (NULL);
	new_line = NULL;
	if (count > 0)
	{
		stash = NULL;
		stash = ft_split(buffer, stash, count);
	}
	while (1)
	{
		if (count == 0 || count % BUFFER_SIZE == 0)
		{
			n = read(fd, buffer, BUFFER_SIZE);
			if (n == 0)
				return(NULL);
		}
		if (ft_back(buffer) > 0 || buffer[0] == '\n')
		{
			ft_clear(stash, buffer);
			new_line = ft_join(new_line, buffer, count);
			if (stash)
				stash = ft_split(&stash[ft_back(buffer) + 1], buffer, count);
			else
				stash = ft_split(stash, buffer, count);
			return (new_line);
		}
		if (ft_back(buffer) == 0)
		{
			new_line = ft_join(new_line, buffer, count);
		}
		count++;
	}
}

#include <stdio.h>

int	main(void)
{
	char	*tab;
	int	fd;
	int	i;

	i = 0;
	fd = open("files/empty", O_RDWR);
    while (i < 6)
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
