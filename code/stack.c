/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:16 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 16:22:36 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int	init_stack(char **argv, t_stack **stack)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (parsing(argv[i]))
		{
			free_stack(*stack);
			return (1);
		}
		num = ft_atoi(argv[i]);
		if (check_doubles(*stack, num))
		{
			ft_printf("Error: insert the number once\n");
			free_stack(*stack);
			return (1);
		}
		append_node((int)num, stack);
		i++;
	}
	return (0);
}

void	append_node(int num, t_stack **stack)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = num;
	new_node->index = 0;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

int	check_doubles(t_stack *stack, long nb)
{
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}
