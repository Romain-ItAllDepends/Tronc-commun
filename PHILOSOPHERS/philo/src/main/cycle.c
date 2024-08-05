/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 08:35:56 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 12:35:12 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	ft_eat(t_philo	*philo)
{
	philo->sleep = 0;
	philo->start_eat = get_time();
	if (is_dead(philo) == 0)
		print_eating(philo);
	if (is_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->vars->must_eat_philo);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->vars->must_eat_philo);
	}
	if (is_dead(philo) == 0)
		ft_usleep(philo->vars->time_to_eat);
	philo->start_eat = 0;
	philo->nb_fork = 0;
	pthread_mutex_lock(&philo->vars->must_eat_philo);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->vars->must_eat_philo);
	philo->think = 0;
	pthread_mutex_lock(&philo->right_fork->fork_t);
	philo->left_fork->currently_used = 0;
	pthread_mutex_unlock(&philo->right_fork->fork_t);
	pthread_mutex_lock(&philo->left_fork->fork_t);
	philo->right_fork->currently_used = 0;
	pthread_mutex_unlock(&philo->left_fork->fork_t);
	philo->eat = 1;
}

static void	get_fork(t_philo *philo)
{
	while (philo->nb_fork != 2)
	{
		pthread_mutex_lock(&philo->left_fork->fork_t);
		if (is_dead(philo) == 0 && philo->left_fork->currently_used == 0)
			get_left_fork(philo);
		pthread_mutex_unlock(&philo->left_fork->fork_t);
		pthread_mutex_lock(&philo->right_fork->fork_t);
		if (is_dead(philo) == 0 && philo->right_fork->currently_used == 0)
			get_right_fork(philo);
		pthread_mutex_unlock(&philo->right_fork->fork_t);
		if (is_dead(philo) > 0)
			break ;
		if (reset_think(philo) == 1)
			break ;
	}
	if (philo->nb_fork == 2 && is_dead(philo) == 0)
		ft_eat(philo);
}

static void	ft_sleep(t_philo *philo)
{
	philo->think = 0;
	philo->sleep = 1;
	philo->eat = 0;
	philo->start_sleep = get_time();
	if (is_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->vars->print);
		if (is_dead(philo) == 0)
			printf("%i %i  is sleeping\n", timestamp(philo), philo->philo_id);
		pthread_mutex_unlock(&philo->vars->print);
	}
	if (is_dead(philo) == 0)
		ft_usleep(philo->vars->time_to_sleep);
	philo->start_sleep = 0;
}

static void	ft_think(t_philo *philo)
{
	if (philo->think == 0)
	{
		philo->think = 1;
		if (is_dead(philo) == 0)
		{
			pthread_mutex_lock(&philo->vars->print);
			if (is_dead(philo) == 0)
				printf("%i %i   is thinking\n", timestamp(philo), philo->philo_id);
			pthread_mutex_unlock(&philo->vars->print);
		}
	}
}

void	*ft_cycle(void *tmp)
{
	t_philo	*philo;

	philo = (t_philo *)tmp;
	ft_think(philo);
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->vars->time_to_eat);
	while (1)
	{
		if (is_dead(philo) == 0)
			ft_think(philo);
		else
			break ;
		if (is_dead(philo) == 0 && philo->eat == 0)
			get_fork(philo);
		else if (is_dead(philo) > 0)
			break ;
		if (is_dead(philo) == 0 && philo->sleep == 0)
			ft_sleep(philo);
		else if (is_dead(philo) > 0)
			break ;
	}
	return (NULL);
}
