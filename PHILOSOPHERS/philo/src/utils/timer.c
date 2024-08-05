/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 06:53:13 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 12:37:24 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_usleep(int usec)
{
	long int		compare;
	long int		start;
	struct timeval	time;

	start = gettimeofday(&time, NULL);
	if (start == -1)
		return (1);
	start = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	while (1)
	{
		compare = gettimeofday(&time, NULL);
		if (compare == -1)
			return (1);
		compare = (time.tv_sec * 1000) + (time.tv_usec / 1000);
		if (compare - start >= usec)
			break ;
		usleep(10);
	}
	return (0);
}

long int	last_time(long int msec)
{
	struct timeval	time;
	long int		current;

	current = gettimeofday(&time, NULL);
	if (current == -1)
		return (-1);
	current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current - msec);
}

long int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	timestamp(t_philo *philo)
{
	return (get_time() - philo->vars->start);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->dead);
	pthread_mutex_lock(&philo->vars->must_eat_philo);
	if (philo->vars->is_dead == 1 || philo->vars->nb_philo_finish == 1)
	{
		pthread_mutex_unlock(&philo->vars->must_eat_philo);
		pthread_mutex_unlock(&philo->vars->dead);
		return (2);
	}
	pthread_mutex_unlock(&philo->vars->must_eat_philo);
	pthread_mutex_unlock(&philo->vars->dead);
	return (0);
}
