/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:41:35 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 12:35:58 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	death_checker(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < vars->nb_philo)
	{
		pthread_mutex_lock(&philo[i].vars->must_eat_philo);
		if (get_time() - philo[i].last_meal >= vars->time_to_die
			&& vars->is_dead == 0)
		{
			pthread_mutex_lock(&philo[i].vars->dead);
			vars->is_dead = 1;
			pthread_mutex_unlock(&philo[i].vars->dead);
			printf_death(&philo[i]);
		}
		pthread_mutex_unlock(&philo[i].vars->must_eat_philo);
		i++;
	}
}

static void	must_eat(t_vars *vars, t_philo *philo)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < vars->nb_philo)
	{
		pthread_mutex_lock(&vars->must_eat_philo);
		if (philo[i].nb_meal >= philo[i].must_eat)
			tmp++;
		i++;
		pthread_mutex_unlock(&vars->must_eat_philo);
	}
	if (tmp == vars->nb_philo)
	{
		pthread_mutex_lock(&vars->must_eat_philo);
		vars->nb_philo_finish = 1;
		pthread_mutex_unlock(&vars->must_eat_philo);
	}
}

void	ft_supervises(t_vars *vars, t_philo *philo)
{
	while (vars->is_dead == 0
		&& vars->nb_philo_finish == 0)
	{
		if (philo[0].must_eat != 0)
			must_eat(vars, philo);
		death_checker(vars, philo);
		usleep(500);
	}
}
