/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:33:54 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/05 16:33:56 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	ft_swap_char(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char	*ft_strrev(char *str)
{
	int	i;
	int	i_end;

	i = 0;
	i_end = 0;
	while (str[i_end] != '\0')
	{
		i_end++;
	}
	i_end--;
	while (i < i_end)
	{
		ft_swap_char(&str[i], &str[i_end]);
		i++;
		i_end--;
	}
	return (str);
}

static void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)malloc(size * count);
	if (!array)
		return (NULL);
	while (i < count * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

char		*ft_itoa(int n)
{
	unsigned int	num;
	char			*str;
	int				i;
	int				size;

	size = (n < 0);
	i = 0;
	num = n * ((n < 0) ? -1 : 1);
	while (num / 10 != 0)
	{
		size++;
		num /= 10;
	}
	if (!(str = ft_calloc(size + 2, sizeof(char))))
		return (NULL);
	num = n * ((n < 0) ? -1 : 1);
	while (num / 10 > 0)
	{
		str[i++] = '0' + num % 10;
		num /= 10;
	}
	str[i++] = '0' + num % 10;
	if (n < 0)
		str[i++] = '-';
	return (ft_strrev(str));
}
