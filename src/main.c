/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:30 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/03/26 23:24:29 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av, char **env)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (parsing(ac, av, &data) == 0)
	{
        printf("Error: invalid arguments\n");
		free(data);
		return (0);
	}
    printf("Number of philosophers: %d\n", data->philo_count);
    printf("Time to die: %lld\n", data->death_time);
    printf("Time to eat: %lld\n", data->eat_time);
    printf("Time to sleep: %lld\n", data->sleep_time);
    printf("Number of times each philosopher must eat: %lld\n", data->eat_count_max);
    free(data);
    return (0);
}
