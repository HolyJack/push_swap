/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 03:20:37 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 21:03:46 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_data *data)
{
	data->min = find_min(data->list_a);
	data->max = find_max(data->list_a);
	if (data->len_a == 3)
	{
		make_step(data, "sa");
		rotate(data, find_rotatepnt(data->list_a));
	}
	else
	{
		while (data->len_a > 3)
		{
			while (data->list_a->val == data->min
				|| data->list_a->val == data->max)
				make_step(data, "ra");
			make_step(data, "pb");
		}
		if (!is_rotated(data->list_a))
			make_step(data, "sa");
		while (data->len_b)
		{
			score(data);
			make_rotation(data);
		}
		rotate(data, find_rotatepnt(data->list_a));
	}
}
