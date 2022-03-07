/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:08:12 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/04 18:08:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(void)
{
	write(1, "Error\n", 7);
	exit(0);
}

t_data *parser(char **argv, int argc)
{
	int i;
	t_list *tmp;
	t_data *data;

	data = new_data();
	i = -1;
	while (++i < argc)
	{
		tmp = new_list(ft_atoi(argv[i]));
		push_back(&(data->list_a), tmp);
	}
	data->len_a = argc;
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

int is_rotated(t_list *list)
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
		sort_medium(data);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = parser(argv + 1, argc - 1);
	//print_list(data->list_a);
	sorter(data);
	printf("a: ");
	print_list(data->list_a);
	printf("b: ");
	print_list(data->list_b);
	return (0);
}
