/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:04:43 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/22 14:04:44 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(1, "Wrong number of arguments!\n", 27);
		return (1);
	}
	while (i < argc)
	{
		if (!(ft_is_all_digit_in_str(argv[i])) || (ft_atoi(argv[i]) <= 0))
		{
			write(1, "Wrong value of argument!\n", 25);
			return (1);
		}
		i++;
	}
	return (0);
}
