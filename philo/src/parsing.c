/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:11:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:47:13 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	add_arguments(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->n_philo = ft_atoll(av[1]);
	data->t_death = ft_atoll(av[2]);
	data->t_eat = ft_atoll(av[3]);
	data->t_sleep = ft_atoll(av[4]);
	data->nb_eat = -1;
	if (ac == 6)
		data->nb_eat = ft_atoll(av[5]);
	if (data->nb_eat == 0 || data->n_philo == 0)
		return (0);
	return (1);
}

int	parsing(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	if (ac >= 5 && ac <= 6)
	{
		i = 1;
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] < '0' || av[i][j] > '9'
					|| ft_atoll(av[i]) > 2147483647 || ft_strlen(av[i]) > 10)
					return (0);
				j++;
			}
			i++;
		}
		return (add_arguments(data, ac, av));
	}
	return (0);
}
