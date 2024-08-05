/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/05 08:13:43 by rgobet           ###   ########.fr       */
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
	struct s_vars		*vars;
	int					philo_id;
	long int			start_eat;
	long int			start_sleep;
	long int			last_meal;
	int					nb_fork;
	int					nb_meal;
	int					think;
	int					sleep;
	int					eat;
	int					must_eat;
	struct s_fork		*right_fork;
	struct s_fork		*left_fork;
	pthread_t			philo_t;
}	t_philo;

/*
* Forks
*/

typedef struct s_fork
{
	int				fork_id;
	int				currently_used;
	pthread_mutex_t	fork_t;
}	t_fork;

/*
* Main structure
*/

typedef struct s_vars
{
	long int			start;
	int					nb_philo;
	int					is_dead;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_philo_finish;
	pthread_mutex_t		must_eat_philo;
	pthread_mutex_t		print;
	pthread_mutex_t		dead;
	struct s_fork		*fork;
}	t_vars;

/*
* Cycle
*/

void			*ft_cycle(void *philo);

/*
* Utils
*/

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			args_are_digit(char **args);
void			args_are_upper_zero(char **args);
void			*ft_calloc(size_t nmemb, size_t size);
void			init_error(t_vars *vars, t_philo *philo);
int				ft_usleep(int usec);
long int		last_time(long int msec);
long int		get_time(void);
int				timestamp(t_philo *philo);
int				is_dead(t_philo *philo);
void			get_right_fork(t_philo *philo);
void			get_left_fork(t_philo *philo);
void			printf_death(t_philo *philo);
void			print_eating(t_philo *philo);
int				reset_think(t_philo *philo);
void			ft_supervises(t_vars *vars, t_philo *philo);

#endif
