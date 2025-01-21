/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:31 by iheb              #+#    #+#             */
/*   Updated: 2025/01/21 16:24:16 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

t_stack	*init_stack(t_stack *a, t_stack *b)
{
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->next = NULL;
	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->next = NULL;
}

