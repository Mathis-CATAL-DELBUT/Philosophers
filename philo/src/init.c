/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:48:03 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/17 21:58:10 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads(t_data *data)
{
	pthread_t	id_death;
	int			i;

	i = -1;
	while (++i < data->n_philo)
		if (pthread_create(&data->philo[i].t_id, NULL, action_philo,
				&data->philo[i]))
			return (1);
	if (pthread_create(&id_death, NULL, ft_philo_death, data))
		return (1);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(data->philo[i].t_id, NULL);
	pthread_join(id_death, NULL);
	return (0);
}

int	init_data_mutex_philo(t_data *data)
{
	int	i;

	i = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->forks || !data->philo)
		return (0);
	memset(data->philo, 0, sizeof(t_philo) * data->n_philo);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->flag, NULL);
	data->start = get_time();
	while (++i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philo[i].eat_info, NULL);
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->n_philo;
		data->philo[i].last_eat = data->start;
	}
	return (init_threads(data));
}

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].eat_info);
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->flag);
	free(data->forks);
	free(data->philo);
}
