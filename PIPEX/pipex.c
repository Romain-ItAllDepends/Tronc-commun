/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:08 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/30 13:33:33 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

static char	*path_verification(char **path, t_vars *vars, int opt);

static void	verification(int ac, char **av)
{
	if (ac != 5 || access(av[1], F_OK) != 0 || access(av[1], R_OK) != 0
		|| access(av[1], W_OK) != 0)
		exit(1);
}

static void	init_path(char **envp, t_vars *vars)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
			&& envp[i][3] == 'H' && envp[i][4] == '=')
			path = ft_split(&envp[i][5], ':');
		i++;
	}
	vars->cmd1[0] = path_verification(path, vars, 0);
	vars->cmd2[0] = path_verification(path, vars, 1);
}

static char	*path_verification(char **path, t_vars *vars, int opt)
{
	int		i;
	char	*tab;
	char	*cmd;

	i = 0;
	tab = NULL;
	while (path[i])
	{
		if (opt == 0)
			cmd = ft_strjoin(path[i], ft_strjoin("/", vars->cmd1[0]));
		if (opt == 1)
			cmd = ft_strjoin(path[i], ft_strjoin("/", vars->cmd2[0]));
		if (access(cmd, X_OK) == 0)
		{
			tab = ft_fill(cmd, path, vars);
			break ;
		}
		i++;
	}
	if (tab == NULL)
	{
		free(path);
		exit(1);
	}
	return (tab);
}

static void	ft_execution(t_vars *vars, char **envp)
{
	pid_t	pid;
	int		n;
	int		m;
	int		fd[2];
	char	test[100];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		execve(vars->file1, vars->cmd1, envp);
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		n = read(fd[0], test, 100);
		ft_printf("%s\n", test);
  dup2(fd[0], 0);
		close(fd[0]);
		m = open(vars->file2, O_WRONLY | O_APPEND);
		if (m == -1)
			exit(1);
		dup2(fd[1], 1);
		execve(vars->file2, vars->cmd2, envp);
		close(m);
		close(fd[1]);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	verification(ac, av);
	vars->file1 = av[1];
	vars->file2 = av[4];
	vars->cmd1 = ft_split(av[2], ' ');
	vars->cmd2 = ft_split(av[3], ' ');
	init_path(envp, vars);
	ft_printf("%s\n", vars->cmd1[0]);
	ft_printf("%s\n", vars->cmd2[0]);
	ft_execution(vars, envp);
	return (0);
}
