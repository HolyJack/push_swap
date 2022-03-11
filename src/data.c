/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:23:07 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 22:45:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*new_data(void)
{
	t_data	*tmp;

	tmp = malloc(sizeof(t_data));
	if (!tmp)
		return (0);
	tmp->i = 0;
	tmp->j = 0;
	tmp->list_a = NULL;
	tmp->list_b = NULL;
	tmp->min = 0;
	tmp->max = 0;
	tmp->flag = 0;
	tmp->len_a = 0;
	tmp->len_b = 0;
	tmp->display_steps = 1;
	return (tmp);
}

void	free_data(t_data *data)
{
	free_list(data->list_a);
	data->list_a = NULL;
	free_list(data->list_b);
	data->list_b = NULL;
	data->len_a = 0;
	data->len_b = 0;
	free(data);
}
