/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 03:10:21 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:34:03 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*copy_list(t_list *list)
{
	t_list	*nlist;

	if (!list)
		return (NULL);
	nlist = NULL;
	while (list)
	{
		push_back(&nlist, new_list(list->val));
		list = list->next;
	}
	return (nlist);
}

t_list	*copy_sublist(t_list *list, int start, int end)
{
	t_list	*nlist;
	t_list	*tmp;

	tmp = list;
	nlist = NULL;
	while (tmp->val != start)
		tmp = tmp->next;
	tmp = tmp->next;
	if (!tmp)
		tmp = list;
	while (tmp->val != end)
	{
		push_back(&nlist, new_list(tmp->val));
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = list;
	}
	return (nlist);
}

t_list	*pop_head(t_list **head)
{
	t_list	*tmp;

	if (!*head)
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	tmp->next = NULL;
	return (tmp);
}

t_list	*pop_val(t_list **head, int val)
{
	t_list	*cur;
	t_list	*tmp;

	if (!head)
		return (NULL);
	cur = *head;
	if (cur->val == val)
	{
		*head = cur->next;
		cur->next = NULL;
		return (cur);
	}
	while (cur->next)
	{
		if (cur->next->val == val)
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			tmp->next = NULL;
			return (tmp);
		}
		cur = cur->next;
	}
	return (NULL);
}

int	in_list(t_list *list, int val)
{
	while (list)
	{
		if (list->val == val)
			return (1);
		list = list->next;
	}	
	return (0);
}
