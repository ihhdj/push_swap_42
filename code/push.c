/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:36 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/02/03 14:04:31 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void	push_instruction(t_stack **src, t_stack **dest)
{
	t_stack	*temp_node;

	if (*src == NULL)
		return ;
	temp_node = *src;
	*src = (*src)->next;
	temp_node->next = *dest;
	*dest = temp_node;
}

void	pa(t_stack **a, t_stack **b)
{
	push_instruction(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_instruction(a, b);
	write(1, "pb\n", 3);
}
