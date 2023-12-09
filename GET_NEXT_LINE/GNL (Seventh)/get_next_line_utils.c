/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:18 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/08 16:59:33 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s || s == NULL)
		return (0);
	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c > 255)
		c = c % 256;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (s[0] == '\0')
		return (-1);
	return (0);
}

char	*ft_split(char *stash, char *buffer)
{
	char	*tab;
	int		i;

	i = (ft_strlen(stash) + ft_strchr(buffer, '\n')) + 2;
	tab = malloc(i * sizeof(char));
	if (tab == 0)
		return (0);
	i = 0;
	while (stash && stash[i])
	{
		tab[i] = stash[i];
		i++;
	}
	while ((i - ft_strlen(stash)) < ft_strchr(buffer, '\n')
		&& (buffer[i - ft_strlen(stash)] != '\n' || i - ft_strlen(stash) == 0))
	{
		tab[i] = buffer[i - ft_strlen(stash)];
		i++;
	}
	tab[i] = '\0';
	if (stash && ft_strchr(stash, '\n') == 0)
		ft_free(stash);
	return (tab);
}

char	*ft_join(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s) + BUFFER_SIZE) + 1);
	if (tab == 0)
		return (NULL);
	while (s && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	while (b[j])
	{
		tab[i++] = b[j];
		b[j++] = 0;
	}
	tab[i] = 0;
	if (s || (s && s[0] == '\0'))
		ft_free(s);
	return (tab);
}

char	*ft_join_d(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s) + BUFFER_SIZE) + 1);
	if (tab == 0)
		return (NULL);
	while (s && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	while (b && b[j])
	{
		tab[i++] = b[j];
		j++;
	}
	tab[i] = 0;
	if (b || (b && b[0] == '\0'))
		ft_free(b);
	return (tab);
}

int	ft_read(int fd, char *buffer, char *stash)
{
	int	n;

	n = read(fd, buffer, BUFFER_SIZE);
	if (n > 0)
		buffer[n] = 0;
	if (n == -1 || (n == 0 && (!stash || stash[0] == '\0')))
	{
		if ((stash && stash[0] == '\0'))
			ft_free(stash);
		// Maybe fo free l'buffer
		free(buffer);
		return (0);
	}
	else if (n == 0)
		return (-8);
	return (n);
}

