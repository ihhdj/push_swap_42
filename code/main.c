/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:33:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/13 13:44:53 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int main(int argc, char **argv)
{
	stack_node	*a;
	// stack_node	*b;

	a = NULL;
	// b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error\n"), 1);
	else if (argc == 2)
		argv = my_split(argv[1], 32);
	init_stack(&a, argv + 1);
}