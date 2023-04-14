/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:00:51 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:47:38 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	ft_print(philo, "has taken a fork");
	if (philo->l_fork == philo->r_fork)
		return (pthread_mutex_unlock(&philo->data->forks[philo->r_fork]), 1);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	ft_print(philo, "has taken a fork");
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
	}
}

int	ft_eat(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->eat_info);
	philo->last_eat = get_time();
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->eat_info);
	ft_usleep(philo->data->t_eat);
	unlock_forks(philo);
	return (0);
}
