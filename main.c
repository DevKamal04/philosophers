/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:06:26 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 02:06:38 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void data_filosofi(char *av[], t_philo *philo,  t_dining *dining)
{
    philo->fork_value = ft_atoi(av[1]);
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
    int k = philo->data;

    if (philo == NULL)
    {
        printf("wrong\n");
    }
    dining->philo = malloc(sizeof(t_philo) * dining->num);
    while (i < philo->data)
    {
        philo[i].id = i + 1;
        (&philo[i])->rght_fork = &dining->forks[i];
        (&philo[i])->left_forks = &dining->forks[(i + 1) % k];
        (&philo[i])->message = &dining->message;
        (&philo[i])->dl_check = &dining->dl_check;
        (&philo[i])->meal_checks = &dining->meal_checks;
        (&philo[i])->time = now();
        (&philo[i])->lst_food = now();
        (&philo[i])->times_to_eat = philo->times_eat;
        (&philo[i])->philo_eat = philo->philo_eat;
        (&philo[i])->philo_sleep = philo->philo_sleep;
        (&philo[i])->finished_dinner = 0;
        (&philo[i])->philo_die = 0;
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


int main(int ac, char *av[])
{
    t_dining dining;
    t_philo philo[MAX_philoOPHERSS];
    pthread_t monitor;
    if (ac < 5 || ac > 6)  
    {
        printf("num_philo tot_life time_to_eat time_to_sleep times_eat\n");
        return 1;
    }
   
data_filosofi(av, philo, &dining);
fork_create(philo, &dining);
data_all(philo, &dining);
 pthread_t *beggars = malloc(philo->data * sizeof(pthread_t));
if (beggars == NULL) {
    perror("Failed to allocate memory for thread IDs");
    return 1;
}
int i = 0;
// if (pthread_create())
 if (pthread_create(&monitor, NULL, (void *)monitor_check, (void *)(philo + i)))
    return (1);
while (i < philo->data)
{
    if (pthread_create(&beggars[i], NULL, (void *)process, (void *)(philo + i)))
    {
        perror("Failed to create thread");
        return 1;
    }
    i++;
}

i = 0;
if(pthread_join(monitor, NULL) != 0)
    return (1);
while (i < philo->data)
{
    pthread_join(beggars[i], NULL);
    i++;
}

free(beggars);

    return (0);
}