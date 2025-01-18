/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:30 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/18 10:57:54 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	parsing(char *str)
{
	check_argument(str);
}
int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return(ft_printf("Error: insert the number once\n"), 1);
			j++;
		}
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
			return(ft_printf("Error: insert only one logical operator\n"), 1);
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return(ft_printf("Error: insert numbers only\n"), 1);
		i++;
	}
	return (0);
}
