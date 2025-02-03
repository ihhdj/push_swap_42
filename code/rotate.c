/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:45:33 by ihhadjal       #+#    #+#             */
/*   Updated: 2025/01/29 17:07:36 by ihhadjal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	rotate_instruction(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = find_last_node(stack);
	*stack = first_node->next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	ra(t_stack **stack_a)
{
	rotate_instruction(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate_instruction(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_instruction(stack_a);
	rotate_instruction(stack_b);
	write(1, "rr\n", 3);
}
