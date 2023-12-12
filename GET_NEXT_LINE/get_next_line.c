/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:00:43 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/11 17:01:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_finish(char *s)
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
	static int	count;
	int			n;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n = BUFFER_SIZE;
	if (count > 0)
		stash = ft_strjoin(buffer, stash, count);
	while (ft_strchr(stash, '\n') == 0 && n != 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = 0;
		if (n < 0)
			return (NULL);
		stash = ft_strjoin(buffer, stash, count++);
	}
	if (ft_strchr(stash, '\n') > 0)
		return (ft_cut(stash, buffer));
	else if (n == 0)
		return (ft_finish(stash));
	return (0);
}
