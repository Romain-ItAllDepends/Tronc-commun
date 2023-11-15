/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:11 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/14 13:32:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_swap()
{
	
}

int	ft_read(int fd, char *buffer)
{
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	
	return (n);
}

char *get_next_line(int fd)
{
	char	*line;
	char	*buffer[BUFFER_SIZE];
	static char	*stash;

	
	return (line);
}
