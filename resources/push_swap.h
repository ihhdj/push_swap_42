/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/21 16:22:13 by ihhadjal         ###   ########.fr       */
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
	struct s_list	*next;
}   				t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack *b;
}			t_data;


void	parsing(char *str);
int		check_argument(char *str);
int     check_doubles(char **argv);
int     check_min_max(char *str);
void    free_argv(char **str);
void    main2(t_stack *a);
t_stack	*init_stack_a(t_stack *a);
#endif