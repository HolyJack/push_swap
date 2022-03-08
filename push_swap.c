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

int arrlen(char **ptr)
{
	int len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
}

t_list *array_tolist(char **array)
{
	int i;
	t_list *tmp;
	t_list *head;
	const int len = arrlen(array);

	i = -1;
	head = NULL;
	while (++i < len)
	{
		tmp = new_list(ft_atoi(array[i]));
		push_back(&(head), tmp);
	}
	return (head);
}

void free_array(char **array)
{
	int	i;
	const int len = arrlen(array);

	i = -1;
	while (++i < len)
		free(array[i]);
	free(array);
}

int is_nbr(char *str)
{
	int	i;
	const int len = ft_strlen(str);

	i = -1;
	while (++i < len)
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int duplicates(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->val == list->val)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

int valid(char **array)
{
	int	i;
	const int len = arrlen(array);

	i = -1;
	while (++i < len)
	{
		if (!is_nbr(array[i]) || !ft_strlen(array[i]))
			return (0);
		if (ft_atoi(array[i]) == 0 && ft_strncmp(array[i], "0", ft_strlen(array[i])))
			return (0);
	}
	return (1);
}

t_data *parser(char **argv, int argc)
{
	int len;
	char **array;
	t_data *data;

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
		return (NULL);
	}
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

	if (argc < 2)
		return (0);
	data = parser(argv + 1, argc - 1);
	//print_list(data->list_a);
	sorter(data);
	printf("a: ");
	print_list(data->list_a);
	printf("b: ");
	print_list(data->list_b);
	free_data(data);
	return (0);
}
