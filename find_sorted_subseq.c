/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sorted_subseq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 03:21:20 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 04:24:06 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_valid_prev_seq(t_list *list, t_list *score, int val, int n)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (++i < n)
	{
		if (val > list->val && max < score->val)
			max = score->val;
		list = list->next;
		score = score->next;
	}
	return (max);
}

t_list	*restore_seq(t_list *list, t_list *score)
{
	int		i;
	int		flag;
	int		max;
	t_list	*nlist;
	t_list	*ltmp;
	t_list	*stmp;

	i = -1;
	max = 0;
	ltmp = list;
	stmp = score;
	nlist = NULL;
	while (++i < lstlen(score))
	{
		if (max < stmp->val)
		{
			max = stmp->val;
			if (nlist)
				free(nlist);
			nlist = new_list(ltmp->val);
		}
		ltmp = ltmp->next;
		stmp = stmp->next;
	}
	while (--max)
	{
		ltmp = list;
		stmp = score;
		flag = 1;
		while (flag)
		{
			if (max == stmp->val && ltmp->val < nlist->val)
			{
				push_front(&nlist, new_list(ltmp->val));
				flag = 0;
			}
			stmp = stmp->next;
			ltmp = ltmp->next;
		}	
	}
	free_list(score);
	return (nlist);
}

t_list	*sorted_subseq(t_list *list)
{
	int		i;
	t_list	*ltmp;
	t_list	*stmp;
	t_list	*score;

	if (!list)
		return (NULL);
	i = 0;
	score = NULL;
	while (i++ < lstlen(list))
		push_back(&score, new_list(1));
	i = -1;
	stmp = score;
	ltmp = list;
	while (++i < lstlen(list))
	{
		stmp->val += max_valid_prev_seq(list, score, ltmp->val, i);
		ltmp = ltmp->next;
		stmp = stmp->next;
	}
	return (restore_seq(list, score));
}

t_list	*biggest_sorted(t_data *data)
{
	t_list	*tmp;
	t_list	*sub1;
	t_list	*sub2;

	tmp = copy_sublist(data->list_a, data->min, data->max);
	sub1 = sorted_subseq(tmp);
	free_list(tmp);
	tmp = copy_sublist(data->list_a, data->max, data->min);
	sub2 = sorted_subseq(tmp);
	free_list(tmp);
	if (lstlen(sub1) > lstlen(sub2))
	{
		free_list(sub2);
		return (sub1);
	}
	data->flag = 1;
	free_list(sub1);
	return (sub2);
}
