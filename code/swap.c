/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:11:30 by ihhadjal       #+#    #+#             */
/*   Updated: 2025/01/28 13:41:53 by ihhadjal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void    swap_instruction(t_stack **stack)
{
    t_stack *temp_node;

    if (!(*stack)->next)
        return ;
    temp_node = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    temp_node->next = *stack;
    *stack = temp_node;
}

void    sa(t_stack **stack_a)
{
    swap_instruction(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b)
{
    swap_instruction(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap_instruction(stack_a);
    swap_instruction(stack_b);
    write(1, "ss\n", 3);
}

void    prep_for_push(t_stack **stack, t_stack *top_node,
                        char stack_name)
{
    while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack) ;
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}