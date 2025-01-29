/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:57:40 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/01/29 21:34:50 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int is_stack_sorted(t_stack *stack)
{
    if (!stack)
        return (0);
    while(stack->next)
    {
        if (stack->value > stack->next->value)
            return (1);
        stack = stack->next;
    }
    return (0);
}
void    small_sort(t_stack  *stack)
{
}