/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:49:54 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:06:35 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_med(t_list *list)
{
	int		med;
	int		len;
	t_list	*tmp;
	t_list	*copy;
	t_list	*sorted;

	sorted = NULL;
	copy = copy_list(list);
	while (copy)
		push_back(&sorted, pop_val(&copy, find_min(copy)));
	tmp = sorted;
	len = lstlen(sorted) / 2;
	while (len--)
		tmp = tmp->next;
	med = tmp->val;
	free_list(sorted);
	return (med);
}
