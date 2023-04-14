/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:49:59 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 03:15:18 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(t_philo *philo, char *str)
{
    long long   time;

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