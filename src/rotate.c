/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:56:41 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 18:19:08 by ejafer           ###   ########.fr       */
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
