/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 03:20:37 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 04:48:33 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_data *data)
{
	if (data->len_a == 3)
	{
		make_step(data, "sa");
		rotate(data, find_rotatepnt(data->list_a));
	}
	else
	{
		while (data->len_a > 3)
			make_step(data, "pb");
		if (!is_rotated(data->list_a) && !is_rotated(data->list_b))
			make_step(data, "ss");
		if (!is_rotated(data->list_a))
			make_step(data, "sa");
		if (!is_rotated(data->list_b))
			make_step(data, "sb");
		while (data->len_b)
		{
			make_step(data, "pa");
			if (data->list_a->val > data->list_a->next->val)
				make_step(data, "ra");
		}
	}
}
