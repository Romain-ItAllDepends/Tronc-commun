/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:01:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/10 14:28:51 by rgobet           ###   ########.fr       */
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

void	free_vars(t_vars *vars)
{
	ft_free(vars->cmd1);
	ft_free(vars->cmd2);
	free(vars);
}

void envp_path_verif(char **envp)
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
