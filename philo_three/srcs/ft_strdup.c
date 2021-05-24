/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:02:27 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/30 23:02:47 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

char		*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = 0;
	while (s1 && s1[count])
		count++;
	str = (char *)malloc(sizeof(*str) * count + 1);
	if (str == NULL)
		return (NULL);
	count = 0;
	while (s1 && s1[count] != '\0')
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
