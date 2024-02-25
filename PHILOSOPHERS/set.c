/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:17:06 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/25 15:31:35 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_start_eat(t_vars *vars, t_philosopher *p, t_fork *fl, t_fork *fr)
{
	fl->start_eat = gettimeofday(&(vars->time->tv_usec), NULL);
	fr->start_eat = gettimeofday(&(vars->time->tv_usec), NULL);
	p->start_eat = gettimeofday(&(vars->time->tv_usec), NULL);
	fl->used = 1;
	fr->used = 1;
	printf("%i %i has taken a fork\n", fl->start_eat, p->num_philo);
	printf("%i %i has taken a fork\n", fr->start_eat, p->num_philo);
	printf("%i %i is eating\n", p->start_eat, p->num_philo);
}

void	set_stop_eat(t_vars *vars, t_philosopher *p, t_fork *fl, t_fork *fr)
{
	fl->used = 0;
	fr->used = 0;
	fl->start_eat = -1;
	fr->start_eat = -1;
	p->start_eat = -1;
	p->last_meal = gettimeofday(&(vars->time->tv_usec), NULL);
}
