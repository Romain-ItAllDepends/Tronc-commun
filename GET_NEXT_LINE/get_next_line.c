/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/15 14:58:11 by rgobet           ###   ########.fr       */
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

char	*ft_swap(char *buffer, char *stash)
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
	return (stash);
}

int	ft_read(int fd, char *buffer)
{
	if (read (fd, buffer, BUFFER_SIZE) < 0)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	static char		*ptr;
	char			*tab;
	long int		size_m;

	tab = ptr;
	ptr = &tab[0];
	if (size == 0)
		size = BUFFER_SIZE;
	size_m = nmemb * size + 2;
	if ((int)size_m < 0 || ((int)size < 0 && (int)nmemb < 0))
		return (NULL);
	tab = malloc(size_m);
	if (tab == 0)
		return (0);
	tab[size_m - 1] = '\0';
	return (tab);
}

char	*get_next_line(int fd)
{
	int			i;
	int			buff;
	char		*line;
	char		buffer[BUFFER_SIZE];
	char	*stash;

	i = 0;
	buff = BUFFER_SIZE;
	if (ft_read(fd, buffer))
		return (0);
	while (i == 0 || stash[i] != '\n')
	{
		if (i == 0 || (buff / i) == 0)
		{
			stash = ft_calloc(sizeof(char), i);
			ft_swap(buffer, stash);
			if (!ft_bn(stash))
				free(stash);
		}
		i++;
	}
	line = ft_substr(stash, 0, ft_strlen_mod(stash));
	free(stash);
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
