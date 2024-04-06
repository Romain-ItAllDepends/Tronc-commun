/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:08 by rgobet            #+#    #+#             */
/*   Updated: 2024/04/06 11:44:03 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_vars *vars, char **envp)
{
	if (vars->cmd1[0] == NULL)
	{
		close(vars->fd[0]);
		close(vars->fd[1]);
		free_vars(vars);
		exit(0);
	}
	close(vars->fd[0]);
	vars->fd_child = open(vars->file1, O_RDONLY);
	if (vars->fd_child == -1)
	{
		perror("Error : ");
		free_vars(vars);
		exit(1);
	}
	dup2(vars->fd_child, STDIN_FILENO);
	dup2(vars->fd[1], STDOUT_FILENO);
	close(vars->fd[1]);
	close(vars->fd_child);
	execve(vars->cmd1[0], vars->cmd1, envp);
	perror("Error : ");
	ft_free(vars->cmd1);
}

static void	parent(t_vars *vars, char **envp)
{
	vars->pid = fork();
	if (vars->pid == -1)
		error(vars, "Error : fork\n");
	if (vars->pid == 0)
	{
		wait(NULL);
		close(vars->fd[1]);
		if (vars->cmd1)
			dup2(vars->fd[0], STDIN_FILENO);
		vars->fd_parent = open(vars->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (vars->fd_parent == -1)
			error(vars, "Error : The file descriptor can't be opened !\n");
		dup2(vars->fd_parent, STDOUT_FILENO);
		close(vars->fd[0]);
		close(vars->fd_parent);
		execve(vars->cmd2[0], vars->cmd2, envp);
		error(vars, "Error : execve\n");
	}
	wait(NULL);
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

	tab = NULL;
	if (vars->cmd1[0] != NULL || opt != 0)
		tab = cmd_verification(vars, path, opt);
	if (tab == NULL)
	{
		dup2(2, 1);
		if (opt == 0)
		{
			if (vars->cmd1[0] != NULL)
				ft_printf("%s: command not found\n", vars->cmd1[0]);
		}
		else
		{
			ft_printf("%s: command not found\n", vars->cmd2[0]);
			error_g(vars, path);
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
	int		opt;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		exit(1);
	init(vars, ac, av);
	opt = envp_path_verif(envp, av, vars);
	init_path(envp, vars, opt);
	if (pipe(vars->fd) == -1)
		exit(1);
	vars->pid = fork();
	if (vars->pid == -1)
		exit(1);
	if (vars->pid == 0)
		child(vars, envp);
	else
		parent(vars, envp);
	close(vars->fd[0]);
	close(vars->fd[1]);
	free_vars(vars);
	return (0);
}
