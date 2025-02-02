/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:22:41 by deniayoubov       #+#    #+#             */
/*   Updated: 2025/02/03 00:37:15 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

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

void    set_target_b(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *target_node;
	long best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b); 
}

void    min_on_top(t_stack **a)
{
	while ((*a)->value != find_smallest(*a)->value)
	{
		if (find_smallest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
