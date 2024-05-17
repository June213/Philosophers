/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:48:06 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 14:22:30 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	ft_write(t_philos *philo, char *str)
{
	pthread_mutex_lock(&philo->args->sync_mutex);
	if (philo->args->death || philo->args->full)
	{
		pthread_mutex_unlock(&philo->args->sync_mutex);
		return (false);
	}
	printf("%llu %d %s\n", current_time() - philo->args->start_time,
		philo->nbr, str);
	pthread_mutex_unlock(&philo->args->sync_mutex);
	return (true);
}

bool	ft_stop(t_philos *philo)
{
	pthread_mutex_lock(&philo->args->sync_mutex);
	if (philo->args->death || philo->args->full)
	{
		pthread_mutex_unlock(&philo->args->sync_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->args->sync_mutex);
	return (false);
}

bool	ft_get_forks(t_philos *philo)
{
	if (ft_stop(philo))
		return (false);
	pthread_mutex_lock(&philo->l_fork);
	if (!ft_write(philo, TAKE_FORK))
	{
		pthread_mutex_unlock(&philo->l_fork);
		return (false);
	}
	if (ft_stop(philo))
		return (false);
	pthread_mutex_lock(&philo->r_fork);
	if (!ft_write(philo, TAKE_FORK))
	{
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		return (false);
	}
	return (true);
}

bool	ft_sleep_think(t_philos *philo)
{
	if (!ft_write(philo, SLEEPING))
		return (false);
	ft_usleep(philo->args->time_sleep);
	if (!ft_write(philo, THINKING))
		return (false);
	return (true);
}

void	*routine(void *src)
{
	t_philos	*philo;

	philo = (t_philos *)src;
	if (philo->nbr % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (!ft_get_forks(philo))
			break ;
		pthread_mutex_lock(&philo->args->sync_mutex);
		philo->count_meal++;
		philo->last_meal_time = current_time();
		pthread_mutex_unlock(&philo->args->sync_mutex);
		ft_write(philo, EATING);
		ft_usleep(philo->args->time_eat);
		pthread_mutex_lock(&philo->args->sync_mutex);
		if (philo->count_meal == philo->args->num_meals)
			philo->args->philos_finished += (philo->args->num_meals != -1);
		pthread_mutex_unlock(&philo->args->sync_mutex);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		if (!ft_sleep_think(philo))
			break ;
	}
		return (NULL);
}
