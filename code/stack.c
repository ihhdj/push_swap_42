/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:31 by iheb              #+#    #+#             */
/*   Updated: 2025/01/28 12:13:41 by deniayoubov      ###   ########.fr       */
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
        parsing(argv[i]);
        num = ft_atoi(argv[i]);
        if (check_doubles(*stack, num))
        {
            ft_printf("Error: insert the number once\n");
            return;
        }
        append_node((int)num, stack);
        i++;
    }
    swap_instruction(stack);
    print_stack(*stack);
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
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}
int check_doubles(t_stack *stack, long nb)
{
    while (stack)
    {
        if (stack->value == nb)
            return (1);
        stack = stack->next;
    }
    return (0);
}
