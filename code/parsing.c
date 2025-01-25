/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:30 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/25 14:46:38 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	parsing(char *str)
{
	check_argument(str);
	check_min_max(str);
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
			return(ft_printf("Error: insert only one logical operator\n"), 1);
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
			return(ft_printf("Error: insert numbers only\n"), 1);
		i++;
	}
	return (0);
}
