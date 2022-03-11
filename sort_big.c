/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:44:36 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:30:21 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_b(t_data *data)
{
	t_list	*slist;

	slist = biggest_sorted(data);
	while (data->len_a - 2 > lstlen(slist))
	{
		if (data->list_a->val != data->max
			&& data->list_a->val != data->min
			&& !in_list(slist, data->list_a->val))
		{
			if (data->list_a->val > data->med)
			{
				make_step(data, "pb");
				make_step(data, "rb");
			}
			else
				make_step(data, "pb");
		}
		else
			make_step(data, "ra");
	}
	free_list(slist);
}

void	push_back_to_a(t_data *data)
{
	while (data->len_b > 0)
	{
		score(data);
		make_rotation(data);
	}
}

void	switch_min_max(t_data *data)
{
	while (data->list_a->val != data->min)
		make_step(data, "ra");
	make_step(data, "sa");
}

void	sort_main(t_data *data)
{
	data->med = find_med(data->list_a);
	data->max = find_max(data->list_a);
	data->min = find_min(data->list_a);
	fill_stack_b(data);
	if (data->flag)
		switch_min_max(data);
	push_back_to_a(data);
	if (is_rotated(data->list_a))
		rotate(data, find_rotatepnt(data->list_a));
}
