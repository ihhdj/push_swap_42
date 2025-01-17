/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:00:30 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/17 14:58:04 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	parsing(char *str)
{
	check_string(str);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return(ft_printf("Error: insert numbers only\n"), 1);
		i++;
	}
	return (0);
}