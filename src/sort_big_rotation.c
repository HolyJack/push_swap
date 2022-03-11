/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:18:44 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 18:36:06 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_ij(t_data *data)
{
	int	r_i;
	int	r_j;
	int	i;
	int	j;

	i = data->i;
	j = data->j;
	r_i = data->len_a - data->i;
	r_j = data->len_b - data->j;
	if (max(i, j) <= min(r_i + j, i + r_j) && max(i, j) <= min(r_i, r_j))
		return ;
	else if (max(r_i, r_j) <= (min(i + r_j, r_i + j)))
	{
		data->i = -r_i;
		data->j = -r_j;
	}
	else
	{
		if (r_i < i)
			data->i = -r_i;
		else
			data->j = -r_j;
	}
}

void	make_rotation_straight(t_data *data)
{
	while (data->i > 0 && data->j > 0)
	{
		make_step(data, "rr");
		data->i--;
		data->j--;
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
}

void	make_rotation_reverse(t_data *data)
{
	while (data->i < 0 && data->j < 0)
	{
		make_step(data, "rrr");
		data->i++;
		data->j++;
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
}

void	make_rotation(t_data *data)
{
	min_ij(data);
	make_rotation_straight(data);
	make_rotation_reverse(data);
	make_step(data, "pa");
}
