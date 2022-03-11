/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:36:56 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:06:31 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *list)
{
	int	min;

	min = list->val;
	while (list)
	{
		if (list->val < min)
			min = list->val;
		list = list->next;
	}
	return (min);
}