/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:52:13 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 14:25:04 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_args	args;
	int i;
	
	if (argc < 5 || argc > 6 || !init_args(&args, argv))
		return (1);
	init_philo(&args);
	i = -1;
	while (++i < args.num_philo)
		pthread_create(&args.philo[i].thread, NULL, routine, &args.philo[i]);
}