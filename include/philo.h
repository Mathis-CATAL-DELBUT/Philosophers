/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:33 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/03/26 23:23:46 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				last_eat;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	int				*death_flag;
	int				*eat_count_flag;
	int				*eat_count_max;
	int				*eat_time;
	int				*sleep_time;
	int				*start_time;
}					t_philo;

typedef struct s_data
{
	int				philo_count;
	long long		death_time;
	long long		eat_time;
	long long		sleep_time;
	long long		eat_count_max;
	// int				start_time;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	*print;
	// pthread_mutex_t	*death;
	// int				death_flag;
	// int				eat_count_flag;
}					t_data;

//Parsing
int					check_argument(t_data **data);
int					add_arguments(t_data **data, int ac, char **av);
int					parsing(int ac, char **av, t_data **data);

#endif /* PHILO_H */