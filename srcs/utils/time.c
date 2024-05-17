/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:38:03 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 14:05:15 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

// Para devolver el tiempo actal en milisegundos

uint64_t	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000ULL + tv.tv_usec / 1000ULL);
}

void	ft_usleep(uint64_t milisec)
{
	uint64_t	now;
	uint64_t	then;

	now = current_time();
	then = current_time();
	while (then - now < milisec)
	{
		usleep(100);
		then = current_time();
	}
}
