/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:07 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 13:32:10 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	if (!stack || stack->next == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	small_sort(t_stack **stack)
{
	t_stack	*biggest_node;

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

void	big_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(a, b);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	small_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}
