/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:31:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/13 16:31:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	while (list->next && list->val <= list->next->val)
		list = list->next;
	if (!list->next)
		return (1);
	return (0);
}
