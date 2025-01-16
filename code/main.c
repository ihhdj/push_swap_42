/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:33:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/16 20:31:47 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int main(int argc, char **argv)
{
	char	**argv_split;
	int		i;

	i = 0;
	argv_split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Error: the argument is empty\n"), 1);
	if (argc == 2)
	{
		argv_split = ft_split(argv[1], 32);
		argv = argv_split;
	}
	parsing(argv);
	if (argv_split)
	{
		while (argv_split[i])
			free (argv_split[i++]);
		free (argv_split);
	}
	return (0);
}