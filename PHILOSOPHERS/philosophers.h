/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/07/10 07:30:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

/*
* Philosophers
*/

typedef struct s_philo
{
	int			philo_id;
	pthread_t	philo_t;
}	t_philo;

/*
* Forks
*/

typedef struct s_fork
{
	int			fork_id;
	pthread_t	fork_t;
}	t_fork;

/*
* Main structure
*/

typedef struct s_vars
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	pthread_t		dead;
	pthread_t		end;
	t_fork	*fork;
	t_philo	*philo;
}	t_vars;

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			args_are_digit(char **args);
void			args_are_upper_zero(char **args);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
