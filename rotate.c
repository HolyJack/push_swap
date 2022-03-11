/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:41 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:31:18 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_rotatepnt(t_list *list)
{
	int	i;
	int	pnt;

	i = 0;
	pnt = 0;
	while (list->next)
	{
		if (list->val > list->next->val)
			pnt = i + 1;
		i++;
		list = list->next;
	}
	return (pnt);
}

void	rotate(t_data *data, int rotate_pnt)
{
	char	*cmd;

	cmd = "ra";
	if (rotate_pnt > data->len_a - rotate_pnt)
	{
		cmd = "rra";
		rotate_pnt = data->len_a - rotate_pnt;
	}
	while (rotate_pnt--)
		make_step(data, cmd);
}

void	make_rotation(t_data *data)
{
	min_ij(data);
	while (data->i > 0 && data->j > 0)
	{
		make_step(data, "rr");
		data->i--;
		data->j--;
	}
	while (data->i < 0 && data->j < 0)
	{
		make_step(data, "rrr");
		data->i++;
		data->j++;
	}
	while (data->i > 0)
	{
		make_step(data, "ra");
		data->i--;
	}
	while (data->j > 0)
	{
		make_step(data, "rb");
		data->j--;
	}
	while (data->i < 0)
	{
		make_step(data, "rra");
		data->i++;
	}
	while (data->j < 0)
	{
		make_step(data, "rrb");
		data->j++;
	}
	make_step(data, "pa");
}
