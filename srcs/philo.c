/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:52:13 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/21 10:04:19 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	check_death_full(t_args *args, int *i)
{
	pthread_mutex_lock(&args->sync_mutex);
	if (current_time() - args->philo[*i].last_meal_time >=
		(unsigned long long)args->time_die
			|| args->philos_finished == args->num_philo)
	{
		if (args->num_meals != -1 &&
			args->philos_finished == args->num_philo)
		{
			args->full = true;
			pthread_mutex_unlock(&args->philo[*i].l_fork);
			printf("Every philosopher has eaten %d times\n", args->num_meals);
		}
		else
		{
			args->death = true;
			pthread_mutex_unlock(&args->philo[*i].l_fork);
			printf("%llu %d died\n",
				current_time() - args->start_time, args->philo[*i].nbr);
		}
		pthread_mutex_unlock(&args->sync_mutex);
		return (true);
	}
	if (*i + 1 == args->num_philo)
		*i = -1;
	pthread_mutex_unlock(&args->sync_mutex);
	return (false);
}

int	main(int argc, char **argv)
{
	t_args	args;
	int i;
	
	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6 || !init_args(&args, argv))
		return (1);
	init_philo(&args);
	i = -1;
	while (++i < args.num_philo)
		pthread_create(&args.philo[i].thread, NULL, routine, &args.philo[i]);
	i = -1;
	while (++i < args.num_philo && !check_death_full(&args, &i))
		i = i + 0;
	i = -1;
	while (++i < args.num_philo)
		pthread_join(args.philo[i].thread, NULL);
	// i = -1;
	// while (++i < args.num_philo)
	// 	pthread_detach(args.philo[i].thread);
	// i = -1;
	// while (++i < args.num_philo)
	// 	pthread_mutex_destroy(&args.philo[i].l_fork);
	// ft_free(args.philo);
	ft_free(&args);
	return (0);
}