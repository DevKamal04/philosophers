/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:05:48 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 02:05:57 by kamsingh         ###   ########.fr       */
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
	int				philo_die;
	int				tot_life;
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
