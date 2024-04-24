/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:19:47 by kamsingh          #+#    #+#             */
/*   Updated: 2024/04/24 19:35:02 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    return 1;
}
int i = 0;
 if (pthread_create(&monitor, NULL, (void *)monitor_check, (void *)(philo + i)) != 0)
    return (1);
while (i < philo->data)
{
    if (pthread_create(&beggars[i], NULL, (void *)process, (void *)(philo + i)) != 0)
    {
        return 1;
    }
    i++;
}

i = 0;
if(pthread_join(monitor, NULL) != 0)
    return (1);
while (i < philo->data)
{
    if (pthread_join(beggars[i], NULL) != 0)
		return (1);
    i++;
}

free(beggars);

    return (0);
}