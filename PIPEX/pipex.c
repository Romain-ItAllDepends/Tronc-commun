/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:08 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/31 11:39:57 by rgobet           ###   ########.fr       */
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
	int		m;
	int		n;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(fd[0]);
		n = open(vars->file1, O_RDONLY);
		if (n == -1)
			exit(1);
		dup2(n, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(vars->cmd1[0], vars->cmd1, envp);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		m = open(vars->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (m == -1)
			exit(1);
		dup2(m, STDOUT_FILENO);
		if (execve(vars->cmd2[0], vars->cmd2, envp) == -1)
			ft_printf("Bitch");
		close(fd[0]);
		close(m);
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
	// ft_printf("%s\n", vars->cmd1[0]);
	// ft_printf("%s\n", vars->cmd2[0]);
	ft_execution(vars, envp);
	return (0);
}
