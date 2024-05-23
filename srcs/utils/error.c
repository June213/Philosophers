/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:11:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/23 09:21:54 by jsalaber         ###   ########.fr       */
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
	if (args->philo)
	{
		free(args->philo);
		args->philo = NULL;
	}
}
