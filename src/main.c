/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:30 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:22:23 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (parsing(ac, av, data) == 0)
		return (printf("Error: invalid arguments\n"), 0);
	init_data_mutex_philo(data);
	printf("Number of philosophers: %d\n", data->n_philo);
	printf("Time to die: %d\n", data->t_death);
	printf("Time to eat: %d\n", data->t_eat);
	printf("Time to sleep: %d\n", data->t_sleep);
	printf("Number of times each philosopher must eat: %d\n", data->nb_eat);
	return (0);
}
