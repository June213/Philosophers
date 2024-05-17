/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:46:16 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 11:05:06 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	init_args(t_args *args, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (!isint(argv[i]))
			return (false);
	args->num_philo = ft_atoi(argv[1]);
	args->time_die = ft_atoi(argv[2]);
	args->time_eat = ft_atoi(argv[3]);
	args->time_sleep = ft_atoi(argv[4]);
	args->num_meals = -1;
	if (argv[5])
	{
		args->num_meals = ft_atoi(argv[5]);
		if (!args->num_meals)
			return (false);
	}
	pthread_mutex_init(&args->sync_mutex, NULL);
	args->start_time = current_time();
	return (true);
}

void	init_philo(t_args *args)
{
	int	i;

	i = 0;
	while (args->num_philo > i)
	{
		args->philo[i].nbr = i + 1;
		args->philo[i].last_meal_time = args->start_time;
		pthread_mutex_init(&args->philo[i].l_fork, NULL);
		if (i + 1 == args->num_philo)
			args->philo[i].r_fork = &args->philo[0].l_fork;
		else
			args->philo[i].r_fork = &args->philo[i + 1].l_fork;
		args->philo[i].args = args;
		i++;
	}
}
