/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:25:23 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/25 15:31:37 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	thinking(t_vars *vars, t_fork *tmp_fork, t_philosopher *tmp_philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (tmp_philo->last_meal >= vars->time_to_die)
			die(vars, tmp_philo);
		if (tmp_fork->used == 0 && tmp_fork->next->used == 0)
		{
			start_eat(vars, tmp_philo);
			break ;
		}
		else if (i == 0)
		{
			printf("%i %i is thinking\n",
				gettimeofday(vars->time->tv_usec, NULL), tmp_philo->num_philo);
		}
		i++;
	}
}

static void	start_sleep(t_vars *vars, t_philosopher *current)
{
	current->start_sleep = gettimeofday(&(vars->time->tv_usec), NULL);
	printf("%i %i has taken a fork\n", current->start_sleep,
		current->num_philo);
	current->start_sleep = gettimeofday(&(vars->time->tv_usec), NULL);
	usleep(vars->time_to_sleep);
	current->start_sleep = -1;
}

static t_fork	*get_fork(t_vars *vars, t_philosopher *current, char side)
{
	t_philosopher	*p;
	t_fork			*f;

	p = current;
	f = vars->fork;
	while (f)
	{
		if (p->num_philo + 1 == vars->number_of_philosophers
			&& f->num_fork == 0 && side == 'l')
			return (f);
		if (p->num_philo == 0 && side == 'r'
			&& f->num_fork + 1 == vars->number_of_philosophers)
			return (f);
		if (p->num_philo == f->num_fork - 1 && side == 'r')
			return (f);
		if (p->num_philo == f->num_fork + 1 && side == 'l')
			return (f);
		f = f->next;
	}
}

static void	start_eat(t_vars *vars, t_philosopher *current)
{
	t_fork			*fl;
	t_fork			*fr;
	t_philosopher	*p;

	p = current;
	fl = get_fork(vars, p, 'l');
	fr = get_fork(vars, p, 'r');
	set_start_eat(vars, p, fl, fr);
	pthread_mutex_lock(&(vars->philo->mutex_l));
	pthread_mutex_lock(&(vars->philo->mutex_r));
	usleep(vars->time_to_eat);
	pthread_mutex_unlock(&(vars->philo->mutex_l));
	pthread_mutex_unlock(&(vars->philo->mutex_l));
	set_stop_eat(p, fl, fr);
	start_sleep(vars, p);
}

void	eat(t_vars *vars)
{
	static int		n;
	t_philosopher	*tmp_philo;
	t_fork			*tmp_fork;

	while (tmp_philo->num_philo != n)
		tmp_philo = tmp_philo->next;
	while (tmp_fork)
	{
		if (tmp_fork->num_fork == n - 1)
			break ;
		tmp_fork = tmp_fork->next;
	}
	thinking(vars, tmp_fork, tmp_philo);
}
