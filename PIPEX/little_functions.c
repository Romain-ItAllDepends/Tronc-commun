/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:48 by rgobet            #+#    #+#             */
/*   Updated: 2024/04/06 12:13:49 by rgobet           ###   ########.fr       */
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

int	verification(char **av, t_vars *vars)
{
	int	fd;
	int	n;

	n = 0;
	if (access(av[4], F_OK) != 0)
	{
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(fd);
	}
	if (access(av[1], F_OK) != 0 || access(av[1], R_OK) != 0
		|| access(av[1], W_OK) != 0)
		error(vars, "Error : Don't have permissions\n");
	if (vars->cmd1[0] != NULL && access(vars->cmd1[0], X_OK) == 0)
		n = 1;
	if (vars->cmd2[0] != NULL && access(vars->cmd2[0], X_OK) == 0)
		n = 2;
	if (vars->cmd1[0] != NULL && access(vars->cmd1[0], X_OK) == 0
		&& access(vars->cmd2[0], X_OK) == 0)
		n = 3;
	return (n);
}

void	init_path(char **envp, t_vars *vars, int opt)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
			&& envp[i][3] == 'H' && envp[i][4] == '=')
		{
			path = ft_split(&envp[i][5], ':');
			break ;
		}
		i++;
	}
	if (i > 0 && path == NULL && opt == 0)
	{
		write (2, "PATH is unset !\n", 16);
		free(vars);
		exit(1);
	}
	verif_cmd(vars, path, opt);
	ft_free(path);
}

char	*execution_right(char *cmd, char **path, t_vars *vars)
{
	char	*tab;

	tab = NULL;
	if (access(cmd, X_OK) == 0)
	{
		tab = ft_fill(cmd, path, vars);
		free(cmd);
	}
	else
		free(cmd);
	return (tab);
}
