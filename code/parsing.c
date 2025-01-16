/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:30 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/16 16:41:04 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	parsing(char **str)
{
	check_string(str);
}
int	check_string(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 1;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != '-' && str[i][j] != '+')
				return (ft_printf("Error: insert numbers only\n"), 1);
			j++;
		}
		i++;
	}
	return (0);
}