/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:26 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 14:14:35 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int	parsing(char *str)
{
	if (check_argument(str) || check_min_max(str))
		return (1);
	else
		return (0);
}

int	check_min_max(char *str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		num = ft_atoi(&str[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (ft_printf("Error: number out of bounds\n"), 1);
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		i++;
	}
	return (0);
}

int	check_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (ft_printf("Error: insert only one logical operator\n"), 1);
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
			return (ft_printf("Error: insert numbers only\n"), 1);
		i++;
	}
	return (0);
}
