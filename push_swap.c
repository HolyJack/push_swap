/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:08:12 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:01:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*parser(char **argv, int argc)
{
	int		len;
	char	**array;
	t_data	*data;

	array = argv;
	if (argc == 1)
		array = ft_split(argv[0], ' ');
	len = arrlen(array);
	data = new_data();
	data->list_a = array_tolist(array);
	data->len_a = len;
	if (duplicates(data->list_a) || !valid(array))
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

int	is_sorted(t_list *list)
{
	while (list->next && list->val <= list->next->val)
		list = list->next;
	if (!list->next)
		return (1);
	return (0);
}

int	is_rotated(t_list *list)
{
	int		flag;
	t_list	*first;

	flag = 0;
	first = list;
	while (list->next)
	{
		if (list->val > list->next->val)
			flag++;
		list = list->next;
	}
	if ((list != first && list->val <= first->val && flag == 1) || flag == 0)
		return (1);
	return (0);
}

void	sorter(t_data *data)
{
	if (is_sorted(data->list_a))
		return ;
	if (is_rotated(data->list_a))
		rotate(data, find_rotatepnt(data->list_a));
	else if (data->len_a < S_THRESHOLD)
		sort_small(data);
	else
		sort_main(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = parser(argv + 1, argc - 1);
	sorter(data);
	free_data(data);
	return (0);
}
