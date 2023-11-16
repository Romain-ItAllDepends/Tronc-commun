/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/16 13:44:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bn(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_swap(char *buffer, char *stash)
{
	static int	i;
	int			j;

	j = 0;
	while (buffer[j])
	{
		stash[i] = buffer[j];
		i++;
		j++;
	}
}

int	ft_read(int fd, char *buffer, int buff)
{
	if (read (fd, buffer, buff) < 0)
		return (1);
	return (0);
}

void	*ft_calloc(char	*buffer, char *stash)
{
	char			save[ft_strlen(stash)];
	char			*tab;
	long int		size_m;

	if (stash)
	{
		ft_join(stash, save);
		stash[0] = '\0';
		free(stash);
	}
	if (!stash)
		size_m = ft_strlen(buffer) + 1;
	else
		size_m = ft_strlen(buffer) + ft_strlen(stash) + 1;
	if ((int)size_m <= 0)
		return (NULL);
	tab = malloc(size_m);
	if (tab == 0)
		return (0);
	if (save)
		ft_join(save, tab);
	tab[size_m - 1] = '\0';
	return (tab);
}

char	*get_next_line(int fd)
{
	int			i;
	int			buff;
	char		*line;
	char		buffer[BUFFER_SIZE];
	static char	*stash;

	i = 0;
	buff = BUFFER_SIZE;
	if (ft_read(fd, buffer, buff))
		return (0);
	while (i == 0 || stash[i] != '\n')
	{
		if (stash[i] == '\0' || stash[i] == '\n')
			break ;
		if (i == 0 || (i % buffer) == 0)
		{
			stash = ft_calloc(buffer, stash);
			ft_swap(buffer, stash);
		}
		i++;
	}
	line = ft_substr(stash, 0, ft_strlen_mod(stash));
	return (line);
}

#include <stdio.h>

int    main(void)
{
    int        fd;
    int        i;
    char    *rsl;

    i = 0;
    fd = open("files/empty", O_RDONLY);
    while (i < 3)
    {
        rsl = get_next_line(fd);
        printf("%s", rsl);
        i++;
        free(rsl);
    }
    close(fd);
    return (0);
}
