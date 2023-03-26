/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:11:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/03/26 23:30:56 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_argument(t_data **data)
{
    if ((*data)->philo_count < 2)
        return (0);
    else if ((*data)->death_time < (*data)->eat_time + (*data)->sleep_time) 
        return (0);
    else if ((*data)->eat_count_max < 1)
        return (0);
    return (1);
}

int	add_arguments(t_data **data, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (i == 1)
			(*data)->philo_count = ft_atoi(av[i]);
		else if (i == 2)
			(*data)->death_time = ft_atoll(av[i]);
		else if (i == 3)
			(*data)->eat_time = ft_atoll(av[i]);
		else if (i == 4)
			(*data)->sleep_time = ft_atoll(av[i]);
		else if (i == 5)
			(*data)->eat_count_max = ft_atoll(av[i]);
		i++;
	}
	return (check_argument(data));
}

int	parsing(int ac, char **av, t_data **data)
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
				if (av[i][j] < '0' || av[i][j] > '9')
					return (0);
				j++;
			}
			i++;
		}
		return (add_arguments(data, ac, av));
	}
	return (0);
}