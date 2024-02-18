/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:09 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/18 15:06:38 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*f(void *nb)
{
	int	n;

	n = *((int *)nb);
	if (n == 1)
		usleep(10000);
	printf("Test, %i\n", n);
	return (NULL);
}

void	wait_threads(t_vars *vars)
{
	t_philosopher	*tmp;

	tmp = vars->philo;
	while (tmp)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (1);
	if (ac < 1)
		return (1);
	init_philosophers(vars, av);
	threads(vars);
	while (vars->fork)
	{
		printf("Number of the fork : %d\n", vars->fork->num_fork);
		printf("Start eating : %d\n", vars->fork->start_eat);
		printf("Philosopher at left : %d\n", vars->fork->philo_l);
		printf("Philosopher at right : %d\n", vars->fork->philo_r);
		printf("Used ? (0 : NO ; 1 : YES) : %d\n", vars->fork->used);
		vars->fork = vars->fork->next;
	}
	wait_threads(vars);
	ft_lstclear_philo(&(vars->philo));
	ft_lstclear_fork(&(vars->fork));
	free(vars);
	return (0);
}
