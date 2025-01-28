/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/28 13:42:55 by ihhadjal      ###   ########.fr       */
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
void    ss(t_stack **stack_a, t_stack **stack_b);
void    push_instruction(t_stack **src, t_stack **dest);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
int 	stack_len(t_stack *stack);
void    rotate_instruction(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
t_stack *find_last_node(t_stack **stack);
#endif