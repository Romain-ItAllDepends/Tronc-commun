/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/14 17:01:05 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct s_timeval {
	time_t		v_sec;
	suseconds_t	tv_usec;
}	t_timeval;

typedef struct s_philosopher {
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	pthread_mutex_t			mutex_l;
	pthread_mutex_t			mutex_r;
	int						num_philo;
	int						start_eat;
	int						start_sleep;
}	t_philosopher;

typedef struct s_fork {
	struct s_fork	*next;
	struct s_fork	*prev;
	int		num_fork;
	int		philo_l;
	int		philo_r;
	int		start_eat;
	int		used;
}	t_fork;

typedef struct s_vars {
	t_philosopher	philo;
	t_timeval		time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				start_time;
}	t_vars;

int	ft_atoi(const char *str);

#endif
