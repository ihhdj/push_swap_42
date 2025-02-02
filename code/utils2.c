/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:40:50 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/02/02 13:51:54 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

t_stack *find_smallest(t_stack *stack)
{
    t_stack *smallest_node;
    t_stack *current_node;

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

void    set_index(t_stack *stack, int stack_len)
{
    t_stack *biggest;
    t_stack *temp;

    while (stack_len-- > 0)
    {
        biggest = NULL;
        temp = stack;
        while (temp)
        {
            if(!temp->index && (biggest == NULL
                || temp->value > biggest->value))
                biggest = temp;
            temp = temp->next;  
        }
        if (biggest)
            biggest->index = stack_len;
    }
}

int find_max_bits(int biggest)
{
    int max_bits;

    max_bits = 0;
    while (biggest > 0)
    {
        biggest >>= 1;
        max_bits++;
    }
    return (max_bits);
}

int find_biggest(t_stack *stack)    
{
    int     biggest;
    t_stack *tmp;
    
    biggest = INT_MIN;
    tmp = stack;
    while (tmp)
    {
        if (tmp->index > biggest)
            biggest = tmp->index;
        tmp = tmp->next;
    }
    return (biggest);
}