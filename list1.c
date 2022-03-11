/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:18:43 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:12:10 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_list(int val)
{
	t_list	*tmp;

	tmp = malloc (sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->val = val;
	tmp->next = NULL;
	tmp->score = 0;
	return (tmp);
}

void	free_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

void	push_back(t_list **head, t_list *new_elem)
{
	t_list	*tmp;

	if (!new_elem)
		return ;
	if (!*head)
	{
		*head = new_elem;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_elem;
}

void	push_front(t_list **head, t_list *new_elem)
{
	if (!new_elem)
		return ;
	if (*head)
		new_elem->next = *head;
	*head = new_elem;
}

int	lstlen(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
