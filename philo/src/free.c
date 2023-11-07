/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanota <tanota@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:36:00 by tanota            #+#    #+#             */
/*   Updated: 2023/10/13 18:36:42 by tanota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_config *conf)
{
	int	i;

	i = 0;
	if (conf->m)
		pthread_mutex_destroy(conf->m);
	while (i < conf->philo_num)
	{
		pthread_mutex_destroy(conf->forks + i);
		i++;
	}
	(free(conf->m), free(conf->forks), free(conf->philo));
	(free(conf->thrds), free(conf));
	conf = NULL;
}
