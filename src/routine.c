/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:49:59 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:22:19 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print);
	if (philo->data->stop_flag == 1 && ft_strncmp(str, "is died", 7))
	{
		pthread_mutex_unlock(&philo->data->print);
		return ;
	}
	time = get_time();
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n", time - philo->data->start, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_unlock(&philo->data->flag);
}

void	*action_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_eat(philo))
			break ;
		ft_print(philo, "is sleeping");
		ft_usleep(philo->data->t_sleep);
		ft_print(philo, "is thinking");
		pthread_mutex_lock(&philo->data->flag);
		if (philo->data->stop_flag == 1)
		{
			pthread_mutex_unlock(&philo->data->flag);
			break ;
		}
		pthread_mutex_unlock(&philo->data->flag);
		ft_usleep(((philo->data->t_death - philo->data->t_eat
						+ philo->data->t_sleep) / 2));
	}
	return (NULL);
}

int	chek_death(t_data *data, int i)
{
	long long	time;

	pthread_mutex_lock(&data->philo[i].eat_info);
	time = get_time() - data->philo[i].last_eat;
	if (time >= data->t_death)
	{
		pthread_mutex_unlock(&data->philo[i].eat_info);
		pthread_mutex_lock(&data->flag);
		data->stop_flag = 1;
		pthread_mutex_unlock(&data->flag);
		ft_print(&data->philo[i], "is died");
		return (1);
	}
	pthread_mutex_unlock(&data->philo[i].eat_info);
	return (0);
}

int	cheak_eat(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&data->philo[i].eat_info);
		if (data->philo[i].nb_eat < data->nb_eat)
		{
			pthread_mutex_unlock(&data->philo[i].eat_info);
			return (0);
		}
		pthread_mutex_unlock(&data->philo[i].eat_info);
	}
	pthread_mutex_lock(&data->flag);
	data->stop_flag = 1;
	pthread_mutex_unlock(&data->flag);
	return (1);
}

void	*ft_philo_death(void *arg)
{
	t_data *data;
	int i;

	data = (t_data *)arg;
	while (1)
	{
		if (data->nb_eat != -1 && cheak_eat(data))
			break ;
		i = -1;
		while (++i < data->n_philo)
			if (chek_death(data, i))
				return (NULL);
		ft_usleep(1);
	}
	return (NULL);
}