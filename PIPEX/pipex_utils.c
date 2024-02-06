/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipiex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:01:16 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/06 11:06:34 by rgobet           ###   ########.fr       */
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
