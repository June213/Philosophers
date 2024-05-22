/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:11:51 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/22 13:09:42 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (EXIT_FAILURE);
}

void	ft_free(t_args args)
{
	int	i;

	i = -1;
	while (++i < args.num_philo - 1)
		free(&args.philo[i]);
}
