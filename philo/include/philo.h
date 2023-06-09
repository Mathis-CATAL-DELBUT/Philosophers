/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 11:15:33 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/04/14 04:57:03 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		t_id;
	pthread_mutex_t	eat_info;
	int				l_fork;
	int				r_fork;
	int				id;
	int				nb_eat;
	long long		last_eat;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	flag;
	int				stop_flag;
	int				n_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	long long		start;
	t_philo			*philo;
}					t_data;

//Parsing
int					add_arguments(t_data *data, int ac, char **av);
int					parsing(int ac, char **av, t_data *data);

//Utils
long long			get_time(void);
void				ft_usleep(long time);

//Init
int					init_data_mutex_philo(t_data *data);
int					init_threads(t_data *data);
void				ft_free(t_data *data);

//Routines
void				*action_philo(void *arg);
void				ft_print(t_philo *philo, char *str);
void				*ft_philo_death(void *arg);
int					chek_eat(t_data *data);
int					cheak_death(t_data *data, int i);

//Action Forks
int					take_forks(t_philo *philo);
void				unlock_forks(t_philo *philo);
int					ft_eat(t_philo *philo);

//Libft
size_t				ft_strlen(const char *s);
long long int		ft_atoll(const char *str);
void				*memset(void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif /* PHILO_H */