/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:00 by tanota            #+#    #+#             */
/*   Updated: 2023/10/14 14:23:12 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	t_config		*conf;

	conf = philo->conf;
	forks = conf->forks;
	if (!(philo->id % 2))
	{
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_unlock(forks);
		else
			pthread_mutex_unlock(forks + philo->id + 1);
		pthread_mutex_unlock(forks + philo->id);
	}
	else
	{
		pthread_mutex_unlock(forks + philo->id);
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_unlock(forks);
		else
			pthread_mutex_unlock(forks + philo->id + 1);
	}
}

static int	ft_print_eat(t_philo *philo)
{
	t_ull	elapsed_ms;

	pthread_mutex_lock(philo->conf->m);
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	elapsed_ms = timestamp_in_ms();
	printf("%lld %d has taken a fork\n", elapsed_ms, philo->id + 1);
	printf("%lld %d has taken a fork\n", elapsed_ms, philo->id + 1);
	printf("%lld %d is eating\n", elapsed_ms, philo->id + 1);
	return (pthread_mutex_unlock(philo->conf->m), false);
}

static void	ft_get_forks2(t_philo *philo)
{
	pthread_mutex_t	*forks;

	forks = philo->conf->forks;
	pthread_mutex_lock(&forks[philo->id]);
	pthread_mutex_lock(&forks[0]);
}

static void	ft_get_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	t_config		*conf;

	conf = philo->conf;
	forks = conf->forks;
	if (philo->id % 2 == 0)
	{
		if (philo->id == conf->philo_num - 1)
		{
			if (philo->conf->philo_num % 2)
				return (ft_get_forks2(philo));
			pthread_mutex_lock(&forks[0]);
		}
		else
			pthread_mutex_lock(&forks[philo->id + 1]);
		pthread_mutex_lock(&forks[philo->id]);
	}
	else
	{
		(usleep(1000), pthread_mutex_lock(&forks[philo->id]));
		if (philo->id == conf->philo_num - 1)
			pthread_mutex_lock(&forks[0]);
		else
			pthread_mutex_lock(&forks[philo->id + 1]);
	}
}

int	ft_eat(t_philo *philo)
{
	if (philo->conf->philo_num == 1)
	{
		write(STDOUT_FILENO, "0 1 has taken a fork\n", 22);
		return (usleep(philo->conf->t_die * 1000), true);
	}
	else if (philo->conf->times_to_eat != -1
		&& philo->eat_num == philo->conf->times_to_eat)
		return (true);
	else
	{
		ft_get_forks(philo);
		if (ft_print_eat(philo))
			return (ft_drop_forks(philo), true);
		usleep(philo->conf->t_eat * 1000);
		pthread_mutex_lock(philo->conf->m);
		philo->t_last_meal = timestamp_in_ms();
		philo->eat_num++;
		pthread_mutex_unlock(philo->conf->m);
		ft_drop_forks(philo);
	}
	return (false);
}
