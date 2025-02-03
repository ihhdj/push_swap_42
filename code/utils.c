/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:24:04 by iheb              #+#    #+#             */
/*   Updated: 2025/01/28 14:52:26 by ihhadjal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	free_argv(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	stack_len(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*find_max_node(t_stack **stack)
{
	t_stack	*current;
	t_stack	*biggest;

	current = *stack;
	biggest = *stack;
	if (*stack == NULL)
		return (NULL);
	while (current)
	{
		if (biggest->value < current->value)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
