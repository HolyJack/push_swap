/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 03:25:15 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:34:22 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int score_rotation(int i, int j, int r_i, int r_j)
{
	int score;
	
	score = MIN(i + r_j, r_i + j);
	if ((MAX(i, j) ) <= score)
		score = MAX(i, j);
	if (MAX(r_i, r_j) <= score)
		score = MAX(r_i, r_j);
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
	min = score_rotation(data->i , 0, data->len_a - data->i , data->len_b);
	j = 0;
	while (tmp)
	{
		i = find_position(data->list_a, tmp);
		if (min > score_rotation(i, j, data->len_a - i, data->len_b - j))
		{
			min = score_rotation(i, j, data->len_a - i, data->len_b - j);
			data->i = i;
			data->j = j;
		}
		tmp = tmp->next;
		j++;
	}
}

void min_ij(t_data *data)
{
	int r_i;
	int r_j;
	int i;
	int j;

	i = data->i;
	j = data->j;
	r_i = data->len_a - data->i;
	r_j = data->len_b - data->j;
	if ((MAX(i, j) ) <= (MIN(r_i + j, i + r_j)) && (MAX(i, j)) <= (MAX(r_i, r_j)))
		return ;
	else if (MAX(r_i, r_j) <= (MIN(i + r_j, r_i + j)))
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
