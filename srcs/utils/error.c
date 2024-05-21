/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junesalaberria <junesalaberria@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:11:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/21 10:03:25 by junesalaber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (EXIT_FAILURE);
}


void	ft_free(t_args *args)
{
	int	i;
	
	i = 0;
	if (args->philo)
	{
		while (i < args->num_philo)
		{
			pthread_mutex_destroy(&args->philo[i].l_fork);
			i++;
		}
		free(args->philo);
	}
	pthread_mutex_destroy(&args->sync_mutex);
	
}