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

#include "philo_one.h"

void	take_fork(t_all *all)
{
	pthread_mutex_lock(&(all->philo->table->forks[all->philo->l_fork]));
	print_message(all->philo, "\033[33m taken a fork\033[39m\n");
	pthread_mutex_lock(&(all->philo->table->forks[all->philo->r_fork]));
	print_message(all->philo, "\033[33m taken a fork\033[39m\n");
}

void	put_fork(t_all *all)
{
	pthread_mutex_unlock(&(all->philo->table->forks[all->philo->l_fork]));
	pthread_mutex_unlock(&(all->philo->table->forks[all->philo->r_fork]));
}
