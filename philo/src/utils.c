/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:00 by tanota            #+#    #+#             */
/*   Updated: 2023/10/13 18:37:11 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_only_digit(char *str)
{
	int	i;

	i = 0;
	if (!ft_strlen(str))
		return (false);
	while (str[i])
	{
		if ('0' > str[i] || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

t_ull	ft_atoull(const char *nptr)
{
	int		i;
	t_ull	res;

	i = 0;
	res = 0;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	parsing_manager(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_only_digit(av[i]))
			return (false);
		if (ft_strlen(av[i]) > 4)
			return (false);
		if (i == 1 && ft_atoi(av[i]) < 1)
			return (false);
		if (i == 1 && ft_atoi(av[i]) > 200)
			return (false);
		if (ft_atoi(av[i]) > 1000)
			return (false);
		if (ac == 4 && i == 3 && ft_atoi(av[i]) < 1)
			return (false);
		i++;
	}
	return (true);
}
