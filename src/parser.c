/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:18:13 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 22:33:42 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*parser(char **argv, int argc)
{
	char	**array;
	t_data	*data;

	array = argv;
	if (arrlen(array) == 1)
		array = ft_split(argv[0], ' ');
	data = new_data();
	data->list_a = array_tolist(array);
	data->len_a = lstlen(data->list_a);
	if (duplicates(data->list_a) || !is_valid(array))
	{	
		if (argc == 1)
			free_array(array);
		free_data(data);
		error();
	}
	if (argc == 1)
		free_array(array);
	return (data);
}
