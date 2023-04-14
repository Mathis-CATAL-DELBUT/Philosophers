/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:30 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:56:36 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data) == 0)
		return (printf("Error: invalid arguments\n"), 0);
	init_data_mutex_philo(&data);
	ft_free(&data);
	return (0);
}
