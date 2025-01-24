/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/24 15:43:01 by ihhadjal         ###   ########.fr       */
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

void	parsing(char *str);
int		check_argument(char *str);
int     check_doubles(char **argv);
int     check_min_max(char *str);
void    free_argv(char **str);
t_stack	*ft_lstlast(t_stack	*lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
#endif