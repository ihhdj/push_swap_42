/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:57:40 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/02/02 02:26:41 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int is_stack_sorted(t_stack *stack)
{
    if (!stack || stack->next == NULL)
        return (1);
    while(stack->next)
    {
        if (stack->value > stack->next->value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void    small_sort(t_stack  **stack)
{
    t_stack *biggest_node;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    biggest_node = find_max_node(stack);
    if (biggest_node == *stack)
        ra(stack);
    else if ((*stack)->next == biggest_node)
        rra(stack);
    if ((*stack)->value > (*stack)->next->value)
        sa(stack);
}

void    set_target_node(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target_node;
    long    best_match;
    
    while (b)
    {
        best_match = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->value > b->value 
                && current_a->value < best_match)
            {
                best_match = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (LONG_MAX == best_match)
            b->target_node = find_smallest(a);
        else
            b->target_node = target_node;
        b = b->next;
    }
}

void    set_price(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (b)
    {
        b->push_price = b->current_postion;
        if (!(b->above_median))
            b->push_price = len_b - (b->current_postion);
        if (b->target_node->above_median)
            b->push_price += b->target_node->current_postion;
        else
            b->push_price += len_a - (b->target_node->current_postion);
        b = b->next;
    }
}