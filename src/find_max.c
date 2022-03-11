/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:36:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 18:32:16 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *list)
{
	int	max;

	max = list->val;
	while (list)
	{
		if (list->val > max)
			max = list->val;
		list = list->next;
	}
	return (max);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
