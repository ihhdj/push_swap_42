/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:22:03 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/20 10:49:45 by iheb             ###   ########.fr       */
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

typedef struct s_list
{
    int             number;
    struct s_list   *next;
    struct s_list   *previous;
    struct s_list   *target_node;
    
}   t_list;

void	parsing(char *str);
int		check_argument(char *str);
int     check_doubles(char **argv);
int     check_min_max(char *str);
void    free_argv(char **str);
void    main2(t_list *a, t_list *b, char **argv);
#endif