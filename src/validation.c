/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:58:16 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 21:12:03 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (tmp->val == list->val)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

int	is_nbr(char *str)
{
	int			i;
	const int	len = ft_strlen(str);

	i = -1;
	while (++i < len)
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	is_valid(char **array)
{
	int			i;
	const int	len = arrlen(array);

	i = -1;
	while (++i < len)
	{
		if (!is_nbr(array[i]) || !ft_strlen(array[i]))
			return (0);
		if (ft_atoi(array[i]) == 0
			&& ft_strncmp(array[i], "0", ft_strlen(array[i])))
			return (0);
	}
	return (1);
}
