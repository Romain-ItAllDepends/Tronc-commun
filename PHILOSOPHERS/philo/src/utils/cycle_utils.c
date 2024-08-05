/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:11:47 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 12:27:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->print);
	if (is_dead(philo) == 0)
		printf("%i %i is eating\n", timestamp(philo), philo->philo_id);
	pthread_mutex_unlock(&philo->vars->print);
}

int	reset_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->must_eat_philo);
	if (philo->nb_fork < 1
		&& last_time(philo->last_meal) < philo->vars->time_to_eat)
	{
		pthread_mutex_unlock(&philo->vars->must_eat_philo);
		return (1);
	}
	else
	{
		philo->think = 0;
		pthread_mutex_unlock(&philo->vars->must_eat_philo);
	}
	return (0);
}
