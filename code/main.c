/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:33:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/28 14:33:57 by ihhadjal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int main(int argc, char **argv)
{
    char    **argv_split;
    int     error;
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
	argv_split = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (ft_printf("Error: the argument is empty\n"), 1);
    if (argc == 2)
    {
        argv_split = ft_split(argv[1], 32);
        argv = argv_split;
    }
    if (argc == 2)
        error = init_stack(argv, &a);
    else
        error = init_stack(argv + 1, &a);
    if (argv_split)
        free_argv(argv_split);
    if (!error)
        main2(a, b);
    return (0);
}

void    main2(t_stack *a, t_stack *b)
{
    if (!is_stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a);
        else if (stack_len(a) == 3)
            small_sort(&a);
        else
            big_sort(&a, &b);
    }
    free_stack(a);
    free_stack(b);
}
