/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruotine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:20:57 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 20:19:13 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void dream(t_philo *philo) 
{
    print_message(philo, 2);
    get_time(philo->philo_sleep);
    print_message(philo, 3);
}

void eating(t_philo *philo) 
{

    pthread_mutex_lock(philo->left_forks);
    print_message(philo, 0);
    pthread_mutex_lock(philo->rght_fork);
    print_message(philo, 0);
    philo->finished_dinner = 1;
    print_message(philo, 1);
    pthread_mutex_lock(philo->meal_checks);
	philo->lst_food = now();
    philo->times_to_eat++;
    pthread_mutex_unlock(philo->meal_checks);
	get_time(philo->philo_eat);
    pthread_mutex_unlock(philo->left_forks);
    pthread_mutex_unlock(philo->rght_fork);
}

void    only_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->left_forks);
    print_message(philo, 0);
    get_time(philo->philo_eat);
    pthread_mutex_unlock(philo->left_forks);
}

void process(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    // pthread_mutex_lock(philo->dl_check);
    // philo->lst_food = now();
    // pthread_mutex_unlock(philo->dl_check);
    if(philo->data == 1)
    {
        get_time(1);
        only_philo(philo);
    }
    if (philo->id % 2 == 1)
		get_time(200);
    while (!dead_lock(philo))
    {
        eating(philo);
        dream(philo);
    }
	return ;
}

