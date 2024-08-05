/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:13:32 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/03 14:02:56 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	args_are_digit(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == 0)
		{
			write(2, "Empty argument !\n", 17);
			exit(1);
		}
		while (args[i][j])
		{
			if (ft_isdigit(args[i][j]) == 0)
			{
				write(2, &args[i][j], 1);
				write(2, ": numeric argument required\n", 28);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	args_are_upper_zero(char **args)
{
	int	i;
	int	nb;

	i = 1;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		if (i == 1 && ft_atoi(args[i]) > 200)
		{
			write(2, "Too many philosophers !\n", 25);
			exit(1);
		}
		if (nb <= 0)
		{
			write(2, "Arguments can't be bellow or equal to zero !\n", 46);
			exit(1);
		}
		i++;
	}
}

void	get_left_fork(t_philo *philo)
{
	if (is_dead(philo) == 0 && philo->left_fork->currently_used == 0)
	{
		philo->left_fork->currently_used = 1;
		pthread_mutex_lock(&philo->vars->print);
		pthread_mutex_lock(&philo->vars->dead);
		if (philo->vars->is_dead == 0)
		{
			printf("%i %i has taken a fork\n",
				timestamp(philo), philo->philo_id);
		}
		pthread_mutex_unlock(&philo->vars->dead);
		pthread_mutex_unlock(&philo->vars->print);
		philo->nb_fork++;
	}
}

void	get_right_fork(t_philo *philo)
{
	if (is_dead(philo) == 0 && philo->right_fork->currently_used == 0)
	{
		philo->right_fork->currently_used = 1;
		pthread_mutex_lock(&philo->vars->print);
		pthread_mutex_lock(&philo->vars->dead);
		if (philo->vars->is_dead == 0)
		{
			printf("%i %i has taken a fork\n",
				timestamp(philo), philo->philo_id);
		}
		pthread_mutex_unlock(&philo->vars->dead);
		pthread_mutex_unlock(&philo->vars->print);
		philo->nb_fork++;
	}
}

void	printf_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->print);
	printf("%i %i died\n", timestamp(philo), philo->philo_id);
	pthread_mutex_unlock(&philo->vars->print);
}
