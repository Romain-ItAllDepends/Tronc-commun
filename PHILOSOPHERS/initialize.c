/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:38:25 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/25 15:31:31 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_fork	*fork_left(int i, t_philosopher *philo,
	t_philosopher *philo_prev, t_fork *lst)
{
	if (i == 0)
		lst->philo_l = ft_lstlast(philo)->num_philo;
	else
		lst->philo_l = philo_prev->num_philo;
	return (lst);
}

static t_fork	*fork_right(t_vars *vars, t_fork *lst,
	t_philosopher *philo)
{
	if (philo->next != NULL)
		lst->philo_r = philo->next->num_philo;
	else
		lst->philo_r = vars->philo->num_philo;
	return (lst);
}

static void	init_fork(t_vars *vars)
{
	int				i;
	t_fork			*lst;
	t_philosopher	*philo;
	t_philosopher	*philo_prev;

	vars->fork = NULL;
	philo = vars->philo;
	i = 0;
	while (philo)
	{
		lst = ft_lstnew_fork();
		lst = fork_left(i, philo, philo_prev, lst);
		lst = fork_right(vars, lst, philo);
		lst->num_fork = i;
		lst->start_eat = -1;
		lst->used = 0;
		ft_lstadd_back_fork(&(vars->fork), lst);
		i++;
		if (i >= 1)
			philo_prev = philo;
		philo = philo->next;
	}
}

void	init_philosophers(t_vars *vars, char **args)
{
	int				i;
	int				nb_t;
	t_philosopher	*lst_philo;

	nb_t = ft_atoi(args[1]);
	vars->philo = NULL;
	i = 0;
	while (i < nb_t)
	{
		lst_philo = ft_lstnew_philo();
		lst_philo->num_philo = i;
		lst_philo->start_eat = -1;
		lst_philo->start_sleep = -1;
		lst_philo->last_meal = gettimeofday(&(vars->time->tv_usec), NULL);
		lst_philo->next = NULL;
		ft_lstadd_back_philo(&(vars->philo), lst_philo);
		i++;
	}
	init_fork(vars);
}

void	threads(t_vars *vars)
{
	t_philosopher	*browse;

	browse = vars->philo;
	while (browse)
	{
		pthread_create(&(browse->thread), NULL, f, &(browse->num_philo));
		pthread_mutex_init(&(browse->mutex_l), NULL);
		pthread_mutex_init(&(browse->mutex_r), NULL);
		browse = browse->next;
	}
}
