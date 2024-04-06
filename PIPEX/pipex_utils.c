/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:01:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/04/06 12:20:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(void **tab)
{
	void	**tmp;

	if (!tab)
		return ;
	tmp = tab;
	while (*tmp)
	{
		free(*(tmp++));
		if (!*tmp)
			break ;
	}
	free(tab);
}

void	verif_cmd(t_vars *vars, char **path, int opt)
{
	if (vars->cmd1[0] == 0)
		write (2, "command is empty !\n", 19);
	if (vars->cmd1[0] == 0 && vars->cmd2[0] == 0)
	{
		ft_free(vars->cmd1);
		ft_free(vars->cmd2);
		ft_free(path);
		free(vars);
		exit(1);
	}
	if (opt == 0 || opt == 2)
		vars->cmd1[0] = path_verification(path, vars, 0);
	if (opt == 0 || opt == 1)
		vars->cmd2[0] = path_verification(path, vars, 1);
}

void	free_vars(t_vars *vars)
{
	if (vars->cmd1)
		ft_free(vars->cmd1);
	if (vars->cmd2)
		ft_free(vars->cmd2);
	if (vars)
		free(vars);
}

int	envp_path_verif(char **envp, char **av, t_vars *vars)
{
	int	i;
	int	j;

	j = verification(av, vars);
	i = 0;
	if (!envp || !envp[0])
	{
		write (2, "The env variable doesn't exist or is empty !", 44);
		exit(1);
	}
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' && envp[i][2] == 'T'
			&& envp[i][3] == 'H' && envp[i][4] == '=')
		{
			i = -1;
			break ;
		}
		i++;
	}
	if (i != -1)
		error(vars, "The PATH is unset !\n");
	return (j);
}

void	init(t_vars *vars, int ac, char **av)
{
	if (ac != 5)
	{
		write(2, "Error : Too many or too less arguments\n", 39);
		free(vars);
		exit(1);
	}
	vars->file1 = av[1];
	vars->file2 = av[4];
	vars->cmd1 = ft_split(av[2], ' ');
	vars->cmd2 = ft_split(av[3], ' ');
}
