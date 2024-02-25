/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:21:04 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/25 15:26:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	die(t_vars *vars, t_philosopher *philo)
{
	printf("%i %i died\n");
	ft_lstclear_philo(&(vars->philo));
	ft_lstclear_fork(&(vars->fork));
	free(vars);
}
