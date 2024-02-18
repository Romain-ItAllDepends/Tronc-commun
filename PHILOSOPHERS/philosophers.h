/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:09:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/02/18 14:52:37 by rgobet           ###   ########.fr       */
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
	pthread_mutex_t			mutex_l;
	pthread_mutex_t			mutex_r;
	pthread_t				thread;
	int						num_philo;
	int						start_eat;
	int						start_sleep;
	struct s_philosopher	*next;
}	t_philosopher;

typedef struct s_fork {
	int		num_fork;
	int		philo_l;
	int		philo_r;
	int		start_eat;
	int		used;
	struct s_fork	*next;
}	t_fork;

typedef struct s_vars {
	t_philosopher	*philo;
	t_fork			*fork;
	t_timeval		time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				start_time;
}	t_vars;

int				ft_atoi(const char *str);
void			ft_lstadd_back_philo(t_philosopher **lst, t_philosopher *new);
void			ft_lstadd_back_fork(t_fork **lst, t_fork *new);
void			init_philosophers(t_vars *vars, char **args);
void			threads(t_vars *vars);
void			*f(void *nb);
t_philosopher	*ft_lstlast(t_philosopher *lst);
void			*ft_calloc(size_t nmemb, size_t size);
t_philosopher	*ft_lstnew_philo(void);
t_fork			*ft_lstnew_fork(void);
void			ft_lstclear_philo(t_philosopher **lst);
void			ft_lstclear_fork(t_fork **lst);

#endif
