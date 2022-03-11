/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:39:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 22:54:29 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **head)
{
	t_list	*sorted_list;
	t_list	*tmp;

	tmp = *head;
	sorted_list = pop_val(&tmp, find_min(tmp));
	while (tmp)
		push_back(&sorted_list, pop_val(&tmp, find_min(tmp)));
	*head = sorted_list;
}

void	apply_instructions(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	if (line)
		line[ft_strlen(line) - 1] = 0;
	while (line && *line)
	{
		make_step(data, line);
		free(line);
		line = get_next_line(0);
		if (line)
			line[ft_strlen(line) - 1] = 0;
	}
	if (line)
		free(line);
}

int	is_same(t_list *list1, t_list *list2)
{
	while (list1 && list2 && list1->val == list2->val)
	{
		list1 = list1->next;
		list2 = list2->next;
		if (!list1 && !list2)
			return (1);
		if (!list1 || !list2)
			return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		silence;
	t_data	*data;
	t_list	*sorted_list;

	if (argc < 2)
		return (0);
	data = parser(argv + 1, argc - 1);
	data->display_steps = 0;
	sorted_list = copy_list(data->list_a);
	sort_list(&sorted_list);
	apply_instructions(data);
	if (is_same(sorted_list, data->list_a))
		silence = write(1, "OK!\n", 4);
	else
		silence = write(1, "KO!\n", 4);
	free_data(data);
	free_list(sorted_list);
	if (silence)
		return (0);
	return (0);
}
