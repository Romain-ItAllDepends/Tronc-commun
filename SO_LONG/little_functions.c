/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:19:22 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/10 09:50:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_mod(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	verification(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P')
		vars->nb_player++;
	if (vars->map[i][j] == 'E')
		vars->nb_exit++;
	if (vars->map[i][j] == 'C')
		vars->nb_collectable++;
	if ((i == ft_strlen_mod(vars->map) - 1 && j == ft_strlen(vars->map[i]) - 1)
		&& (vars->nb_collectable == 0 || vars->nb_player != 1
			|| vars->nb_exit != 1))
	{
		if (vars->nb_exit != 1)
			write (2, "Error : Only one exit per map is autorized !\n", 45);
		else if (vars->nb_player != 1)
			write (2, "Error : Only one player per map is autorized !\n", 47);
		else if (i == ft_strlen_mod(vars->map) - 1
			&& j == ft_strlen(vars->map[i]) - 1
			&& vars->nb_collectable == 0)
			write (2,
				"Error : You need at least one collectable per map !\n", 52);
		ft_free(vars->map);
		free(vars);
		exit(1);
	}
}

char	**ft_fill(t_vars *vars)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_strlen_mod(vars->map) + 1));
	if (!tab)
		ft_error_three(vars);
	while (vars->map[i])
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * (ft_strlen(vars->map[i]) + 1));
		if (!tab[i])
			ft_error_two(vars, tab);
		while (vars->map[i][j])
		{
			tab[i][j] = vars->map[i][j];
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	forbidden_char(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] != '0'
			&& vars->map[i][j] != '1'
			&& vars->map[i][j] != 'P'
			&& vars->map[i][j] != 'C'
			&& vars->map[i][j] != 'E')
			{
				write (2,
					"Error : An unknown character sliped on the map !\n", 54);
				ft_free(vars->map);
				free(vars);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
