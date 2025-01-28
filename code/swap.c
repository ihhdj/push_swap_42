/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:11:30 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/01/28 13:41:53 by deniayoubov      ###   ########.fr       */
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