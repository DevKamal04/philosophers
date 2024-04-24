/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:05:48 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 09:57:00 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/time.h>
# define MAX_philoOPHERSS 200
# define EATING 1


typedef struct t_philo
{
	pthread_t		beggars;
	pthread_t		monitor;
	int				data;
	int				id;
	int				fork_value;
	int				philo_sleep;
	int				philo_eat;
	int				*philo_die;
	int				tot_life;
	int				dead_info;
	int				times_eat;
	int				times_to_eat;
	int				check_eat;
	int				check_sleep;
	pthread_mutex_t *mutex;
	pthread_mutex_t *left_forks;
	pthread_mutex_t *rght_fork;
	pthread_mutex_t	*message;
	pthread_mutex_t	*meal_checks;
	pthread_mutex_t	*dl_check;
	int				time;
	int				lst_food;
	int				counter;
	int 			finished_dinner;

}	t_philo;

typedef struct s_dining
{
	int					num;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	meal_checks;
	pthread_mutex_t	dl_check;
	t_philo	*philo;
}		t_dining;

void		data_all(t_philo *philo, t_dining *dining);
void		*init_filosofi(t_philo *philo, t_dining *dining);
int			ft_atoi(const char *str);
void		data_filosofi(char *av[], t_philo *philo,  t_dining *dining);
void		memori(t_philo *philo);
int			check_error(t_philo *philo);
void		print_filosofi(t_philo *philo);
void		dream(t_philo *philo);
void		think(t_philo *philo);
void		eating(t_philo *philo);
void		fork_create(t_philo *philo, t_dining *dining);
void		process(void *arg);
int			now(void);
size_t		get_time(size_t time);
void		print_message(t_philo *philo, int i);
void		initialize(t_philo *philo);
void		ft_error();
void		one_philo(t_philo *philo);
// void		monitor_check(void *arg);
int			dead_lock(t_philo *philo);
void *monitor_check(void *arg);
int			check_the_died_philo(t_philo *philo);
void		only_philo(t_philo *philo);
#endif
