/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 12:27:40 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	parsing(int nb_arg, char **args)
{
	if (!(nb_arg == 5 || nb_arg == 6))
	{
		write (2, "Too many or too less arguments !\n", 34);
		exit(1);
	}
	args_are_digit(args);
	args_are_upper_zero(args);
}

static void	init_philo_fork(t_vars *vars, t_philo *philo, char **args)
{
	int	i;

	i = 0;
	while (i != vars->nb_philo)
	{
		vars->fork[i].fork_id = i + 1;
		vars->fork[i].currently_used = 0;
		philo[i].philo_id = i + 1;
		philo[i].nb_fork = 0;
		philo[i].nb_meal = 0;
		philo[i].think = 0;
		philo[i].sleep = 0;
		philo[i].eat = 0;
		philo[i].last_meal = get_time();
		philo[i].must_eat = ft_atoi(args[5]);
		philo[i].vars = vars;
		pthread_mutex_init(&vars->fork[i].fork_t, NULL);
		if (i != 0)
			philo[i].left_fork = &vars->fork[i - 1];
		else
			philo[i].left_fork = &vars->fork[vars->nb_philo - 1];
		philo[i].right_fork = &vars->fork[i];
		i++;
	}
}

static void	init(t_vars *vars, t_philo *philo, char **args)
{
	int	i;

	i = 0;
	vars->start = get_time();
	vars->is_dead = 0;
	vars->nb_philo_finish = 0;
	vars->nb_philo = ft_atoi(args[1]);
	vars->time_to_die = ft_atoi(args[2]);
	vars->time_to_eat = ft_atoi(args[3]);
	vars->time_to_sleep = ft_atoi(args[4]);
	if (pthread_mutex_init(&vars->dead, NULL) != 0)
		init_error(vars, philo);
	if (pthread_mutex_init(&vars->print, NULL) != 0)
		init_error(vars, philo);
	if (pthread_mutex_init(&vars->must_eat_philo, NULL) != 0)
		init_error(vars, philo);
	vars->fork = ft_calloc(sizeof(t_fork), vars->nb_philo);
	if (!philo || !vars->fork)
		init_error(vars, philo);
	init_philo_fork(vars, philo, args);
}

static void	threads(t_vars *vars, t_philo *philo)
{
	int	i;

	i = 0;
	if (philo && vars && vars->fork)
	{
		while (i < vars->nb_philo)
		{
			if (philo && &philo[i] && pthread_create(&philo[i].philo_t, NULL,
					(void *)&ft_cycle, (void *)&philo[i]) != 0)
				init_error(vars, philo);
			i++;
		}
		ft_supervises(vars, philo);
		i = 0;
		while (i < vars->nb_philo)
		{
			if (pthread_join(philo[i].philo_t, NULL) != 0)
				init_error(vars, philo);
			i++;
		}
		pthread_mutex_destroy(&vars->dead);
		pthread_mutex_destroy(&vars->print);
		pthread_mutex_destroy(&vars->must_eat_philo);
	}
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	t_philo	*philo;

	philo = NULL;
	parsing(ac, av);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (1);
	philo = ft_calloc(sizeof(t_philo), ft_atoi(av[1]));
	if (!philo)
		return (1);
	init(vars, philo, av);
	threads(vars, philo);
	free(philo);
	free(vars->fork);
	free(vars);
	return (0);
}
