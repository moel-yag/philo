/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:39:54 by moel-yag          #+#    #+#             */
/*   Updated: 2025/07/01 13:29:42 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

long long ft_atoi(const char *str)
{
	long long result;
	int sign;
	int i;

	result = 0;
	sign = 1;
	i = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}

bool ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool large_number(const char *arg, int i)
{
	long long num;

	num = ft_atoi(arg);
	printf("Parsed number: %lld\n", num); // Debugging line
	if (num < 0 || (i == 0 && num > 200)) // Check for overflow
		return (true);
	return (false);
}

bool is_valid_arg(int ac, char *args[])
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!args[i] || !*args[i])
			return (false);
		if (large_number(args[i], i ))
			return (false);
		int j = 0;
		while (j < (int)ft_strlen(args[i]))
		{
			if (!ft_isdigit(args[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}