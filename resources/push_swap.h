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

# include "libft/header/ft_printf.h"
# include "libft/header/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				value;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}					t_stack;

int					parsing(char *str);
int					check_argument(char *str);
int					check_doubles(t_stack *stack, long nb);
int					check_min_max(char *str);
void				free_argv(char **str);
void				append_node(int num, t_stack **stack);
int					init_stack(char **argv, t_stack **stack);
void				print_stack(t_stack *stack);
void				swap_instruction(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				push_instruction(t_stack **src, t_stack **dest);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
int					stack_len(t_stack *stack);
void				rotate_instruction(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_last_node(t_stack **stack);
void				reverse_rotate_instruction(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				main2(t_stack *a);
int					is_stack_sorted(t_stack *stack);
void				small_sort(t_stack **stack);
t_stack				*find_max_node(t_stack **stack);
void				free_stack(t_stack *stack);
t_stack				*find_smallest(t_stack *stack);
void				big_sort(t_stack **a, t_stack **b);
void				current_index(t_stack *stack);
void				init_nodes_a(t_stack *a, t_stack *b);
void				set_target_a(t_stack *a, t_stack *b);
void				cost_analysis_a(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);
void				init_nodes_b(t_stack *a, t_stack *b);
void				set_target_b(t_stack *a, t_stack *b);
void				move_b_to_a(t_stack **a, t_stack **b);
void				min_on_top(t_stack **a);
void				move_a_to_b(t_stack **a, t_stack **b);
#endif