/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:48 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/30 09:00:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_fill(char *s, char **path, t_vars *vars)
{
	int		i;
	char	*tab;

	tab = malloc(ft_strlen(path[0]) * sizeof(char) + 1);
	if (!tab)
	{
		if (vars->path1)
			free(vars->path1);
		free(vars);
		free(path);
		exit(1);
	}
	i = 0;
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	tab = ft_calloc((1 + ft_strlen(s1) + ft_strlen(s2)), sizeof(char));
	i = 0;
	j = 0;
	if (tab == 0)
		return (0);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	return (tab);
}

