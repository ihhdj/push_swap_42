/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:40:50 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/02/02 01:46:29 by deniayoubov      ###   ########.fr       */
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