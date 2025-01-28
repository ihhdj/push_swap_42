/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniayoubov <deniayoubov@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/28 13:42:11 by deniayoubov      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include "libft/header/ft_printf.h"
# include "libft/header/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}   				t_stack;

void	parsing(char *str);
int		check_argument(char *str);
int 	check_doubles(t_stack *stack, long nb);
int     check_min_max(char *str);
void    free_argv(char **str);
void    append_node(int num, t_stack **stack);
void    init_stack(char **argv, t_stack **stack);
void    print_stack(t_stack *stack);
void    swap_instruction(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b)
#endif