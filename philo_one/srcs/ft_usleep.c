/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:59:14 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/28 18:59:38 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_usleep(long u_time)
{
	struct timeval	time;
	long			current;

	gettimeofday(&time, NULL);
	current = transform_time(time);
	while (transform_time(time) < current + u_time)
	{
//		usleep(10);
		gettimeofday(&time, NULL);
	}
}
