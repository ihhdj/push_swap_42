/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:24:04 by iheb              #+#    #+#             */
/*   Updated: 2025/01/24 15:42:05 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

void    free_argv(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free (str);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last -> next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstlast(t_stack	*lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}