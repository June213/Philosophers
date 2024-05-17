/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalaber <jsalaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:47:15 by jsalaber          #+#    #+#             */
/*   Updated: 2024/05/17 09:27:24 by jsalaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	while (str[i])
		i++;
	return (i);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c != ' ' && c != '\n' && c != '\f'
		&& c != '\t' && c != '\v' && c != 'r')
		return (0);
	return (1);
}

bool	isint(char *str)
{
	size_t	len;
	char	*int_max;

	if (*str == '+')
		str++;
	len = ft_strlen(str);
	if (len > 10)
		return (false);
	if (len == 10)
	{
		while (ft_isdigit(*str) && *str <= *int_max++)
			str++;
	}
	else
	{
		while (ft_isdigit(*str))
			str++;
	}
	return (!*str && true);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	result;
	size_t		i;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result < 0)
			return ((sign != -1) * -1);
		i++;
	}
	return (result * sign);
}
