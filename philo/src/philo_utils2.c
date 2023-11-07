/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:00 by tanota            #+#    #+#             */
/*   Updated: 2023/10/13 23:45:59 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_alive(t_config *conf)
{
	t_philo	*philo;
	int		i;
	t_ull	death;

	philo = conf->philo;
	i = 0;
	while (i < conf->philo_num)
	{
		if (conf->times_to_eat != philo->eat_num)
		{
			death = philo[i].t_last_meal + conf->t_die;
			if (death <= timestamp_in_ms())
			{
				conf->stop_thread = true;
				return (ft_print_death(&philo[i]), false);
			}
		}
		i++;
	}
	return (true);
}

int	ft_all_eat(t_config *conf)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = conf->philo;
	if (conf->times_to_eat == -1)
		return (false);
	else
	{
		while (i < conf->philo_num)
		{
			if (philo[i].eat_num < conf->times_to_eat)
				return (false);
			i++;
		}
	}
	conf->stop_thread = true;
	return (true);
}
