/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:14:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/20 16:07:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s2)
		return (0);
	tab = ft_calloc((1 + ft_strlen(s1) + ft_strlen(s2)), sizeof(char));
	i = 0;
	j = 0;
	if (tab == 0)
		return (0);
	while (s1 && s1[i])
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
	if (s1)
		free(s1);
	return (tab);
}

static char	*get_map(int fd, t_vars *vars)
{
	int		n;
	char	*buf;
	char	*map;

	map = NULL;
	buf = ft_calloc(11, sizeof(char));
	if (!buf)
		ft_error_one(vars);
	while (map == NULL || n > 0)
	{
		n = read(fd, buf, 10);
		if (n == -1)
			ft_error_one(vars);
		buf[n] = 0;
		map = ft_strjoin(map, buf);
	}
	if (map[0] == 0)
	{
		free(map);
		free(buf);
		ft_error_one(vars);
	}
	free(buf);
	no_void(vars, map);
	return (map);
}

static void	rectangular_map(t_vars *vars)
{
	int	length;
	int	tmp;
	int	i;

	i = 0;
	vars->nb_collectable = 0;
	vars->nb_player = 0;
	vars->nb_exit = 0;
	vars->nb_move = 0;
	while (vars->map[i])
	{
		if (i > 0)
			tmp = length;
		length = ft_strlen(vars->map[i]);
		if (i != 0 && (tmp != length || (tmp == length + 1
					&& vars->map[i + 1] == NULL)))
		{
			write (2, "Error : The map need to be rectangular !\n", 41);
			ft_free(vars->map);
			free(vars);
			exit(1);
		}
		i++;
	}
	forbidden_char(vars);
}

static void	map_verification(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		if (vars->map[i] == NULL)
			break ;
		while (vars->map[i][j])
		{
			if (vars->map[0][j] != '1' || vars->map[i][0] != '1'
			|| vars->map[i][ft_strlen(vars->map[i]) - 1] != '1'
			|| vars->map[ft_strlen_mod(vars->map) - 1][j] != '1')
			{
				write (2, "Error : Your map isn't closed by walls !\n", 41);
				ft_free(vars->map);
				free(vars);
				exit(1);
			}
			verification(vars, i, j);
			j++;
		}
		i++;
	}
}

void	init_map(char *path, t_vars *vars)
{
	int		fd;
	int		length;
	char	*map;

	length = ft_strlen(path);
	if (path[length - 1] != 'r' || path[length - 2] != 'e'
		|| path[length - 3] != 'b' || path[length - 4] != '.')
	{
		write (2, "Error : Wrong map extension !\n", 30);
		free(vars);
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error\n", 6);
		free(vars);
		exit(1);
	}
	map = get_map(fd, vars);
	close(fd);
	vars->map = ft_split(map, '\n');
	free(map);
	rectangular_map(vars);
	map_verification(vars);
}
