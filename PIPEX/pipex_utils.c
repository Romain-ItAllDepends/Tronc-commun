/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:01:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/20 15:24:19 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_vars *vars)
{
	perror("Error : ");
	ft_free(vars->cmd1);
	ft_free(vars->cmd2);
	free(vars);
	exit(1);
}

void	error_g(t_vars *vars, char **path)
{
	ft_free(vars->cmd1);
	ft_free(vars->cmd2);
	ft_free(path);
	free(vars);
	exit(1);
}

void	verif_cmd(t_vars *vars, char **path)
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

void	envp_path_verif(char **envp)
{
	int	i;

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
	{
		write (2, "The PATH is unset !", 19);
		exit(1);
	}
}
