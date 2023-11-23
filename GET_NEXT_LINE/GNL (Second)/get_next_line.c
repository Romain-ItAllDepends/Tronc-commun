/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/18 16:46:42 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bn(char *s, int opt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(s[i])
	{
		if (s[i] == '\n' && i != 0)
		{
			j++;
			if (opt > 0)
			{
				if (opt == j)
					return (i + 1);
			}
			else
				return (i + 1);
		}
		i++;
	}
	return (0);
}

void	ft_swap(char *buffer, char *stash, int opt)
{
	static int	i;
	int			j;
	int			n;

	j = 0;
	if (opt == 1)
	{
		n = 0;
		while (stash[n])
		{
			stash[n] = '\0';
			n++;
		}
	}
	else
	{
		while (buffer[j])
		{
			stash[i] = buffer[j];
			i++;
			j++;
		}
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
	static int		x;

	if (stash)
	{
		ft_join(stash, save, 0, save);
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
	ft_swap(save, tab, 1);
	ft_join(&save[ft_bn(save, x++)], tab, 0, save);
	ft_join(buffer, tab, 1, save);
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
	while ((!stash || stash[i] != '\n') && i < ft_strlen(stash) + 1)
	{
		if (i == 0 || (i % buff) == 0)
		{
			stash = ft_calloc(buffer, stash);
			ft_swap(buffer, stash, 0);
		}
		if (stash && ft_bn(stash, 0))
			break ;
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
    while (i < 6)
    {
        rsl = get_next_line(fd);
        printf("%s", rsl);
        i++;
        free(rsl);
    }
    close(fd);
    return (0);
}
