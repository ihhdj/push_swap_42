/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:33:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/20 19:28:11 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int main(int argc, char **argv)
{
    int     i;
    char    **argv_split;
    t_list  *a;
    t_list  *b;

	argv_split = NULL;
    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (ft_printf("Error: the argument is empty\n"), 1);
    if (argc == 2)
    {
		i = 0;
        argv_split = ft_split(argv[1], 32);
        argv = argv_split;
    }
    else
        i = 1;
    while (argv[i])
        parsing(argv[i++]);
    check_doubles(argv);
    main2(a, b, argv);
    if (argv_split)
        free_argv(argv_split);
    return (0);
}

void    main2(t_list *a, t_list *b, char **argv)
{
	init_stack_a(&a, argv + 1);
}
