/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:59:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:17:08 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arrlen(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
}

t_list	*array_tolist(char **array)
{
	int			i;
	t_list		*tmp;
	t_list		*head;
	const int	len = arrlen(array);

	i = -1;
	head = NULL;
	while (++i < len)
	{
		tmp = new_list(ft_atoi(array[i]));
		push_back(&(head), tmp);
	}
	return (head);
}

void	free_array(char **array)
{
	int			i;
	const int	len = arrlen(array);

	i = -1;
	while (++i < len)
		free(array[i]);
	free(array);
}
