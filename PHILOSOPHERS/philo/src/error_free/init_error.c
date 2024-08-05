/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:55:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/03 13:03:09 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	init_error(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&vars->dead);
	pthread_mutex_destroy(&vars->print);
	pthread_mutex_destroy(&vars->must_eat_philo);
	while (i != vars->nb_philo)
	{
		pthread_detach(philo[i].philo_t);
		pthread_mutex_destroy(&vars->fork[i].fork_t);
		i++;
	}
	free(philo);
	free(vars->fork);
	free(vars);
	exit(1);
}
