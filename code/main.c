/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:33:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/17 18:07:07 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int main(int argc, char **argv)
{
	char	**argv_split;
	int		i;

	i = 1;
	argv_split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error: the argument is empty\n"), 1);
	if (argc == 2)
	{
		i = 0;
		argv_split = ft_split(argv[1], 32);
		argv = argv_split;
		while (argv[i])
			parsing(argv[i++]);
	}
	while (argv[i])
		parsing(argv[i++]);
	if (argv_split)
		free_argv(argv_split);
	return (0);
}
