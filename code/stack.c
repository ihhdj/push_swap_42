/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:31 by iheb              #+#    #+#             */
/*   Updated: 2025/01/25 12:18:46 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void    init_stack(char **argv, t_stack **stack)
{
    int     i;
    long    num;

    i = 0;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        append_node((int)num, stack);
        i++;
    }
}

void    append_node(int num, t_stack **stack)
{
    t_stack *new_node;
    t_stack *tmp;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->next = NULL;
    new_node->value = num;
    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        tmp = *stack;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}