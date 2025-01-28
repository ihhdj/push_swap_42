/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:45:33 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/01/28 19:50:59 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void    rotate_instruction(t_stack **stack)
{
    t_stack *last_node;

    if (*stack == NULL)
        return ;
    last_node = find_last_node(stack);
    *stack = (*stack)->next;
    last_node->next = *stack;
    *stack = last_node;
}

void    ra(t_stack **stack_a)
{
    rotate_instruction(stack_a);
    write(1, "ra\n", 3);
}
void    rb(t_stack **stack_b)
{
    rotate_instruction(stack_b);
    write(1, "rb\n", 3);
}
void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate_instruction(stack_a);
    rotate_instruction(stack_b);
    write(1, "rr\n", 3);
}
t_stack *find_last_node(t_stack **stack)
{
    if (*stack == NULL)
        return (NULL);
    while ((*stack)->next)
    {
        *stack = (*stack)->next;
    }
    return (*stack);
}