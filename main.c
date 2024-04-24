/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:06:26 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 20:13:33 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void data_filosofi(char *av[], t_philo *philo,  t_dining *dining)
{
    philo->fork_value = ft_atoi(av[0]);
    philo->data = ft_atoi(av[1]);
    dining->num = ft_atoi(av[1]);
    philo->tot_life = ft_atoi(av[2]);
    philo->philo_eat = ft_atoi(av[3]);
    philo->philo_sleep = ft_atoi(av[4]);
    if (av[5])
        philo->times_eat = ft_atoi(av[5]);
}

void    data_all(t_philo *philo, t_dining *dining)
{
    int i = 0;
    
    if (philo == NULL)
    {
        printf("wrong\n");
    }
    dining->philo = malloc(sizeof(t_philo) * dining->num);
    philo->dead_info = 0;
    while (i < philo->data)
    {
        philo[i].id = i + 1;
        (&philo[i])->rght_fork = &dining->forks[i];
        (&philo[i])->left_forks = &dining->forks[(i + 1) % philo->data];
        (&philo[i])->message = &dining->message;
        (&philo[i])->dl_check = &dining->dl_check;
        (&philo[i])->meal_checks = &dining->meal_checks;
        (&philo[i])->time = now();
        (&philo[i])->lst_food = now();
        (&philo[i])->times_to_eat = philo->times_eat;
        (&philo[i])->philo_eat = philo->philo_eat;
        (&philo[i])->philo_sleep = philo->philo_sleep;
        (&philo[i])->tot_life = philo->tot_life;
        (&philo[i])->finished_dinner = 0;
        (&philo[i])->philo_die = &philo->dead_info;
        i++;
    }
}

void    fork_create(t_philo *philo, t_dining *dining)
{
    int i;
    
    i = 0;
    pthread_mutex_init(&dining->message, NULL);
    pthread_mutex_init(&dining->meal_checks, NULL);
    pthread_mutex_init(&dining->dl_check, NULL);
    dining->forks = malloc(sizeof(pthread_mutex_t) * philo->data);
    while (i < philo->data)
    {
        if (pthread_mutex_init(&dining->forks[i], NULL) != 0)
            printf("error\n");
        i++;
    }
}

void       ft_error()
{
    write(1,"ERROR\n", 6);
}

