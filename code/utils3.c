/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:48 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 13:32:50 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	t_stack	*current_node;

	smallest_node = stack;
	current_node = stack;
	while (current_node)
	{
		if (smallest_node->value > current_node->value)
			smallest_node = current_node;
		current_node = current_node->next;
	}
	return (smallest_node);
}
