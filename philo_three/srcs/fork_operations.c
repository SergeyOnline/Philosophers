/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:57:39 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 18:58:15 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	take_fork(t_philo *philo)
{
	sem_wait(philo->table->steward);
	sem_wait(philo->table->forks);
	print_message(philo, "\033[33m taken a fork\033[39m\n");
	sem_wait(philo->table->forks);
	print_message(philo, "\033[33m taken a fork\033[39m\n");
	sem_post(philo->table->steward);
}

void	put_fork(t_philo *philo)
{
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}
