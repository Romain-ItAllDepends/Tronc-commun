/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:08 by rgobet            #+#    #+#             */
/*   Updated: 2024/01/31 14:44:03 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_vars *vars, char **envp)
{
	close(vars->fd[0]);
	vars->fd_child = open(vars->file1, O_RDONLY);
	if (vars->fd_child == -1)
		exit(1);
	dup2(vars->fd_child, STDIN_FILENO);
	dup2(vars->fd[1], STDOUT_FILENO);
	close(vars->fd[1]);
	if (execve(vars->cmd1[0], vars->cmd1, envp) == -1)
	{
		perror("Error : ");
		ft_free(vars->cmd1);
		ft_free(vars->cmd2);
		free(vars);
		exit(1);
	}
	close(vars->fd_child);
}

static void	parent(t_vars *vars, char **envp)
{
	wait(NULL);
	close(vars->fd[1]);
	dup2(vars->fd[0], STDIN_FILENO);
	vars->fd_parent = open(vars->file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (vars->fd_parent == -1)
	{
		perror("Error : ");
		ft_free(vars->cmd1);
		ft_free(vars->cmd2);
		free(vars);
		exit(1);
	}
	dup2(vars->fd_parent, STDOUT_FILENO);
	if (execve(vars->cmd2[0], vars->cmd2, envp) == -1)
	{
		perror("Error : ");
		ft_free(vars->cmd1);
		ft_free(vars->cmd2);
		free(vars);
		exit(1);
	}
	close(vars->fd[0]);
	close(vars->fd_parent);
}

static char	*cmd_verification(t_vars *vars, char **path, int opt)
{
	int		i;
	char	*tab;
	char	*cmd;
	char	*post_cmd;

	i = 0;
	tab = NULL;
	while (path[i] && tab == NULL)
	{
		if (opt == 0)
		{
			post_cmd = ft_strjoin("/", vars->cmd1[0]);
			cmd = ft_strjoin(path[i], post_cmd);
			free(post_cmd);
		}
		if (opt == 1)
		{
			post_cmd = ft_strjoin("/", vars->cmd2[0]);
			cmd = ft_strjoin(path[i], post_cmd);
			free(post_cmd);
		}
		tab = execution_right(cmd, path, vars);
		i++;
	}
	return (tab);
}

char	*path_verification(char **path, t_vars *vars, int opt)
{
	char	*tab;

	tab = cmd_verification(vars, path, opt);
	if (tab == NULL)
	{
		if (opt == 0)
		{
			ft_printf("%s: command not found\n", vars->cmd1[0]);
			return (vars->cmd2[0]);
		}
		else
		{
			ft_printf("%s: command not found\n", vars->cmd2[0]);
			return (vars->cmd2[0]);
		}
	}
	if (opt == 0)
		free(vars->cmd1[0]);
	else
		free(vars->cmd2[0]);
	return (tab);
}

int	main(int ac, char **av, char **envp)
{
	t_vars	*vars;

	verification(ac, av);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	vars->file1 = av[1];
	vars->file2 = av[4];
	vars->cmd1 = ft_split(av[2], ' ');
	vars->cmd2 = ft_split(av[3], ' ');
	init_path(envp, vars);
	if (pipe(vars->fd) == -1)
		exit(1);
	vars->pid = fork();
	if (vars->pid == -1)
		exit(1);
	if (vars->pid == 0)
		child(vars, envp);
	else
		parent(vars, envp);
	ft_free(vars->cmd1);
	ft_free(vars->cmd2);
	free(vars);
	return (0);
}
