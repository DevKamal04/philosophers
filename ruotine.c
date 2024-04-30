/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruotine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:20:57 by kamsingh          #+#    #+#             */
/*   Updated: 2024/05/01 00:23:41 by kamsingh         ###   ########.fr       */
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
    print_message(philo, 1);
    pthread_mutex_lock(philo->meal_checks);
	philo->lst_food = now();
    philo->times_to_eat++;
    pthread_mutex_unlock(philo->meal_checks);
    philo->finished_dinner = 1;
	get_time(philo->philo_eat);
    pthread_mutex_unlock(philo->left_forks);
    pthread_mutex_unlock(philo->rght_fork);
}

void    only_philo(t_philo *philo)
{
    pthread_mutex_lock(philo->left_forks);
    print_message(philo, 0);
    philo->one_dinner = 1;
    pthread_mutex_unlock(philo->left_forks);
    return ;
}

void process(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    if (philo->data == 1)
    {
        while (!died_philo(philo))
        {
        only_philo(philo);
        return ;
        }
    }
    if (philo->id % 2 == 0)
		get_time(10);
    while (!died_philo(philo))
    {
        eating(philo);
        if (philo->times_to_eat == philo->times_eat)
            break;
        dream(philo);
    }
	return ;
}

