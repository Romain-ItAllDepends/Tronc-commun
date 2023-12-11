/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:57:18 by rgobet            #+#    #+#             */
/*   Updated: 2023/12/11 14:14:51 by rgobet           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

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
	/*
	if (s[0] == '\0')
		return (-1);
	*/
	return (0);
}

char	*ft_strjoin(char *b, char *s, int n)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc ((ft_strlen(s) + BUFFER_SIZE) + 1);
	if (tab == 0)
		return (0);
	while (s && s[i])
	{
		tab[i] = s[i];
		i++;
	}
	while (b[j])
	{
		tab[i + j] = b[j];
		b[j] = 0;
		j++;
	}
	tab[i + j] = 0;
	if (ft_strchr(tab, '\n') > 0 || n < BUFFER_SIZE)
		free(s);
	return (tab);
}

void	save(char *s, char *b, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		b[j] = s[j];
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		b[j] = 0;
		j++;
	}
}

char	*cut(char *s, char *b)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (s[i] != '\n' || s[i] == 0)
		i++;
	if (s[i] == '\n' || s[i] == 0)
		i++;
	tab = malloc (i + 1);
	while (j < i)
	{
		tab[j] = s[j];
		j++;
	}
	tab[j] = 0;
	i = 0;
	while (s[j++])
		i++;
	save(&s[j - i], b, i);
	free(s);
	return (tab);
}
