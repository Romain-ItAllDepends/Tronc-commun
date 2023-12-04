/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:18 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/04 16:01:41 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	ft_strlen(char *s, int opt)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (opt == 1 && s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_split(char *stash, char *buffer)
{
	char	*tab;
	int		i;

	i = (ft_strlen(stash, 0) + ft_strlen(buffer, 1)) + 2;
	tab = malloc(i * sizeof(char));
	if (tab == 0)
		return (0);
	i = 0;
	if (stash)
	{
		while (stash[i++])
			tab[i - 1] = stash[i - 1];
	}
	i--;
	while (buffer[i - ft_strlen(buffer, 2)])
	{
		tab[i] = buffer[i - ft_strlen(stash, 0)];
		i++;
	}
	tab[i] = '\0';
	if ((stash || buffer[0] == '\0') && ft_strlen(stash, 1) == 0)
		free(stash);
	if (stash && ft_strlen(stash, 1) == 0)
		stash = NULL;
	return (tab);
}

char	*ft_join(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (s)
		tab = malloc ((ft_strlen(s, 0) + ft_strlen(b, 0)) * sizeof(char) + 2);
	else
		tab = malloc ((ft_strlen(b, 0)) * sizeof(char) + 1);
	if (tab == 0)
		return (NULL);
	if (s)
	{
		while (s[i++])
			tab[i] = s[i];
	}
	while (b[j])
	{
		tab[i++] = b[j];
		b[j++] = 0;
	}
	tab[i] = 0;
	if (s || b[0] == '\0')
		free(s);
	if (s)
		s = NULL;
	return (tab);
}

int	ft_read(int fd, char *buffer, char *stash)
{
	int	n;

	n = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	if (n == -1 || (n == 0 && stash[0] == '\0'))
		return (0);
	else if (n == 0)
	{
		free(stash);
		stash = NULL;
		return (-8);
	}
	return (n);
}

