/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:17:53 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/01/13 13:18:47 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/push_swap.h"

int	count_words(char *str, char separator)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		while (str[i] == separator && str[i])
			i++;
		if (str[i])
			j++;
		while (str[i] != separator && str[i])
			i++;	
	}
	return (j);
}

char	*get_next_word(char *str, char separator)
{
	static int	j;
	int			len;
	int			i;
	char		*new_str;
	
	j = 0;
	i = 0;
	len = 0;
	while (str[j] == separator)
		j++;
	while (str[j + len] != separator && str[j + len])
		len++;
	new_str = malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	while(str[j] != separator && str[j])
		new_str[i++] = str[j++];
	new_str[i] = '\0';
	return (new_str);
}

char	**my_split(char *str, char separator)
{
	int		words;
	char	**res;
	int		i;

	i = 0;
	words = count_words(str, separator);
	if (!words)
		exit(EXIT_FAILURE);
	res = malloc(sizeof(char *) * (words + 2));
	if (!res)
		return (NULL);
	while (words >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
		}
		res[i++] = get_next_word(str, separator);
		words--;
	}
	res[i] = NULL;
	return(res);
}