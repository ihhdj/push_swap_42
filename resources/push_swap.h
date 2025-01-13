/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/13 14:25:57 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/header/ft_printf.h"
# include "libft/header/libft.h"

typedef struct s_stack_node
{
	int		value;
	struct	s_stack_node *target;
	struct	s_stack_node *previous;
	struct	s_stack_node *next;
}	stack_node;

void	init_stack(stack_node **a, char **argv);
char	**my_split(char *str, char separator);
long	ft_atol(char *str);
#endif