/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:19:03 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/12 00:31:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	push(t_list **fhead, t_list **shead, int *flen, int *slen)
{
	t_list	*tmp;

	if (!*shead)
		return ;
	tmp = pop_head(shead);
	push_front(fhead, tmp);
	(*flen)++;
	(*slen)--;
}

void	reverse(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
}

void	reverse_rotate(t_list **head)
{
	t_list	*first;
	t_list	*last;
	t_list	*slast;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	slast = *head;
	last = *head;
	while (last->next)
	{
		slast = last;
		last = last->next;
	}
	slast->next = NULL;
	last->next = first;
	*head = last;
}

void	make_step(t_data *data, char *name)
{
	if (data->display_steps)
	{
		ft_putstr_fd(name, 1);
		ft_putstr_fd("\n", 1);
	}
	if (ft_strncmp(name, "sa", 2) == 0 || ft_strncmp(name, "ss", 2) == 0)
		swap(&(data->list_a));
	if (ft_strncmp(name, "sb", 2) == 0 || ft_strncmp(name, "ss", 2) == 0)
		swap(&(data->list_b));
	if (ft_strncmp(name, "pa", 2) == 0)
		push(&(data->list_a), &(data->list_b), &(data->len_a), &(data->len_b));
	if (ft_strncmp(name, "pb", 2) == 0)
		push(&(data->list_b), &(data->list_a), &(data->len_b), &(data->len_a));
	if (ft_strncmp(name, "ra", 2) == 0 || ft_strncmp(name, "rr", 3) == 0)
		reverse(&(data->list_a));
	if (ft_strncmp(name, "rb", 2) == 0 || ft_strncmp(name, "rr", 3) == 0)
		reverse(&(data->list_b));
	if (ft_strncmp(name, "rra", 3) == 0 || ft_strncmp(name, "rrr", 3) == 0)
		reverse_rotate(&(data->list_a));
	if (ft_strncmp(name, "rrb", 3) == 0 || ft_strncmp(name, "rrr", 3) == 0)
		reverse_rotate(&(data->list_b));
}
