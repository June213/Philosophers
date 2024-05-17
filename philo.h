/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:22:57 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 14:23:16 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdint.h> //para almacenar el tiempo en milisegundos (uint64_t)

# define MALLOC_ERR "Error: malloc\n"
# define TAKE_FORK "has taken a fork\n"
# define EATING "is eating\n"
# define SLEEPING "is sleeping\n"
# define THINKING "is thinking\n"
# define DIED "died\n"

typedef struct s_philos
{
	int				nbr;
	uint64_t		last_meal_time;
	int				count_meal;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	struct s_args	*args;
}	t_philos;

typedef struct s_args
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_meals;
	int				philos_finished;
	bool			death;
	bool			full;
	uint64_t		start_time;
	pthread_mutex_t	sync_mutex;
	struct s_philos	*philo;
}	t_args;

// UTILS
bool		isint(char *str);
int			ft_atoi(const char *str);
uint64_t	current_time(void);
void		ft_usleep(uint64_t milisec);
void		ft_error(char *str);
void		*routine(void *src);


//INIT
bool		init_args(t_args *args, char **argv);
void		init_philo(t_args *args);

#endif