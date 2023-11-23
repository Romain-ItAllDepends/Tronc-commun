/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:26:20 by rgobet            #+#    #+#             */
/*   Updated: 2023/11/21 14:51:52 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_struct_init(struct s_next_line newline, int fd)
{
	int	i;
	int	n;
	char	buffer[BUFFER_SIZE];

	i = 0;
	if (read(fd, newline->stash, BUFFER_SIZE))
		return (NULL);
	while (newline->next != NULL)
	{
		
	}
}

char	*get_next_line(int fd)
{
	t_next_line *newline;

	newline = malloc(sizeof(*newline));
	if (newline == NULL)
		return (NULL);
}
