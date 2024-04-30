/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dying.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:24:04 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/30 12:10:41 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void print_message(t_philo *philo, int i)
{
    char *str = 0;
    
    if (i == 1)
        str = "eating";
    else if (i == 2)
        str = "sleeping";
    else if (i == 3)
        str = "thinking";
    else if (i == 0)
        str = "has taken fork";
    else if (i == 4)
        str = "is died";
    pthread_mutex_lock(philo->message);
    if (!dead_lock(philo))
        printf("%d %d is %s\n", now() - philo->time,  philo->id, str);
    pthread_mutex_unlock(philo->message);
}

int dead_lock(t_philo *philo)
{
    pthread_mutex_lock(philo->dl_check);
    if (*(philo->philo_die) == 1) 
    {
        pthread_mutex_unlock(philo->dl_check); 
        return(1);
    }
    pthread_mutex_unlock(philo->dl_check);
    return (0);
}

int check_the_died_philo(t_philo *philo)
{
    int i;
    i = 0;
    while (i < philo->data)
    {
        pthread_mutex_lock(philo->meal_checks);
        if (now() - philo[i].lst_food >= philo[i].tot_life && philo[i].finished_dinner == 1)
            {
                pthread_mutex_unlock(philo->meal_checks);
                print_message(philo, 4);
                pthread_mutex_lock(philo->dl_check);
                *(philo->philo_die) = 1;
                pthread_mutex_unlock(philo->dl_check);
                return (1);
            }
        pthread_mutex_unlock(philo->meal_checks);
        i++;
        }
    return (0);
}

int check_the_died_philo_with_eatingf(t_philo *philo)
{
    int i;
    i = 0;
    while (i < philo->data)
    { 
        pthread_mutex_lock(philo->meal_checks);
        if (philo->times_to_eat == philo->times_eat)
        {
            pthread_mutex_unlock(philo->meal_checks);            
            return (1);
        }
        pthread_mutex_unlock(philo->meal_checks);   
        i++;
    }
    return (0);
}

void *monitor_check(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (1)
    { 
        if (check_the_died_philo(philo) || check_the_died_philo_with_eatingf(philo))
            break ;
    }
    return (arg);
}
