/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:34:36 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/23 16:46:46 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int	count;
	static char	buffer[BUFFER_SIZE + 1];
	static char *line;

	if (count > 0)
		line = ft_strjoin(line, buffer);
	while (1)
	{
		if (ft_back(line) == 1)
			return (line);
		if (ft_back(line) == 0)
		{
			ft_read(fd, buffer);
			line = ft_split(line, buffer, count);
		}
		count++;
	}
}
