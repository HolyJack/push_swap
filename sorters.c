/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:44:36 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/07 14:44:36 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list)
{
	int max;

	max = list->val;
	while (list)
	{
		if (list->val > max)
			max = list->val;
		list = list->next;
	}
	return (max);
}


int	find_min(t_list *list)
{
	int min;

	min = list->val;
	while (list)
	{
		if (list->val < min)
			min = list->val;
		list = list->next;
	}
	return (min);
}

int	find_min_score(t_list *list)
{
	int min;

	min = list->score;
	while (list)
	{
		if (list->score < min)
			min = list->val;
		list = list->next;
	}
	return (min);
}


void sort_small(t_data *data)
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
		if (!is_sorted(data->list_a))
		{
			if (find_rotatepnt(data->list_a) == 1)
				make_step(data, "ra");
			else
				make_step(data, "rra");
		}
		while (data->len_b)
		{
			make_step(data, "pa");
			if (data->list_a->val > data->list_a->next->val)
				make_step(data, "ra");
		}
	}
}

int find_position(t_list *list, t_list *tomove)
{
	int i;

	i = 0;
	while (list->next)
	{
		if (list->val < tomove->val && tomove->val < list->next->val)
			return (i + 1);
		list = list->next;
		i++;
	}
	return (0);
}

int score_rotation(t_data *data)
{
	int tmp;
	int score;
	int r_i;
	int r_j;

	r_i = data->len_a - data->i + 1;
	r_j = data->len_b - data->j + 1;
	score = MAX(data->i, data->j);
	tmp = MAX(r_i, r_j);
	score = MIN(score, tmp);
	score = MIN(score, r_i + data->j);
	score = MIN(score, r_j + data->i);
	return (score);
}

void score(t_data *data)
{
	int i;
	int j;
	int min;
	t_list *tmp;

	tmp = data->list_b;
	data->i = find_position(data->list_a, tmp);
	data->j = 0;
	min = score_rotation(data);
	j = 0;
	while (tmp)
	{
		i = find_position(data->list_a, tmp);
		if (min > score_rotation(data))
		{
			min = score_rotation(data);
			data->i = i;
			data->j = j;
		}
		tmp = tmp->next;
		j++;
	}
}

void make_rotation(t_data *data)
{
	//printf("i = %d, j = %d\n",data->i, data->j);
	if (data->i > data->len_a - data->i)
		data->i = -(data->len_a - data->i);
	if (data->j > data->len_b - data->j)
		data->j = -(data->len_b - data->j);
	
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

void sort_medium(t_data *data)
{
	data->max = find_max(data->list_a);
	data->min = find_min(data->list_a);
	while (data->len_a > 2)
	{
		if (data->list_a->val != data->max && data->list_a->val != data->min)
			make_step(data, "pb");
		else
			make_step(data, "ra");
	}
	while (data->len_b > 0)
	{
		score(data);
		make_rotation(data);
	}
	if (is_rotated(data->list_a))
		rotate(data, find_rotatepnt(data->list_a));
}