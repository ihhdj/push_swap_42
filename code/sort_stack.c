/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:57:40 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/02/02 13:50:32 by deniayoubov      ###   ########.fr       */
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
void    sort_five(t_stack **a, t_stack **b)
{
    int len;

    len = stack_len(*a);
    while (len--)
    {
        if ((*a)->index == 0 || (*a)->index == 1)
            pb(a, b);
        else
            ra(a);
    }
    small_sort(a);
    pa(a, b);
    pa(a, b);
    if ((*a)->index > (*a)->next->index)
        sa(a);
}

void    radix_sort(t_stack **a, t_stack **b)
{
    int biggest;
    int max_bits;
    int i;
    int j;

    biggest = find_biggest(*a);
    max_bits = find_max_bits(biggest);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j <= biggest)
        {
            if (((*a)->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
            j++;
        }
        while (*b)
            pa(a, b);
        i++;
    }
}