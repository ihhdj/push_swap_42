/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:47 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 13:31:49 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	reverse_rotate_instruction(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	second_last_node = *stack;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node->next = *stack;
	second_last_node->next = NULL;
	*stack = last_node;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_instruction(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_instruction(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_instruction(stack_a);
	reverse_rotate_instruction(stack_b);
	write(1, "rrr\n", 4);
}
