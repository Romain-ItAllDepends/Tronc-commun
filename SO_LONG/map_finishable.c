/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_finishable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:22:13 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/09 11:22:14 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**condition(char **map, int i, int j);

static void	player_pos(char **map, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (map[*i])
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'P')
				break ;
			*j += 1;
		}
		if (*j != ft_strlen(map[*i]))
			break ;
		*i += 1;
	}
}

void	finishable(t_vars *vars)
{
	int		i;
	int		j;
	char	**map;

	map = ft_fill(vars);
	player_pos(map, &i, &j);
	j++;
	while (map[i])
	{
		while (map[i][j])
			map = condition(map, i, j++);
		i++;
		j = 0;
	}
	player_pos(map, &i, &j);
	while (i >= 0 && map[i])
	{
		while (j >= 0 && map[i][j])
			map = condition(map, i, j--);
		j = ft_strlen(map[i--]) - 1;
	}
	i = 0;
	while (map[i++])
		map = security_finishable(map);
	finishable_verif(vars, map);
}

char	**security_finishable(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			map = condition(map, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	i = ft_strlen_mod(map) - 1;
	j = ft_strlen(map[i]) - 1;
	while (i >= 0 && map[i])
	{
		while (j >= 0 && map[i][j])
			map = condition(map, i, j--);
		j = ft_strlen(map[i--]) - 1;
	}
	return (map);
}

void	finishable_verif(t_vars *vars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
			{
				write (2, "Error : The map can't be finished !\n", 36);
				ft_free(vars->map);
				ft_free(map);
				free(vars);
				exit(1);
			}
			j++;
		}
		i++;
	}
	ft_free(map);
}

static char	**condition(char **map, int i, int j)
{
	if ((map[i][j] != '1' && map[i + 1][j] == 'V')
			|| (map[i][j] != '1' && map[i - 1][j] == 'V')
			|| (map[i][j] != '1' && map[i][j - 1] == 'V')
			|| (map[i][j] != '1' && map[i][j + 1] == 'V')
			|| (map[i][j] != '1' && map[i + 1][j] == 'P')
			|| (map[i][j] != '1' && map[i - 1][j] == 'P')
			|| (map[i][j] != '1' && map[i][j - 1] == 'P')
			|| (map[i][j] != '1' && map[i][j + 1] == 'P'))
		map[i][j] = 'V';
	return (map);
}
