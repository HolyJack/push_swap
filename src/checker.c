/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:39:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/13 16:58:35 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **head)
{
	t_list	*sorted_list;
	t_list	*tmp;

	tmp = *head;
	sorted_list = pop_val(&tmp, find_min(tmp));
	while (tmp)
		push_back(&sorted_list, pop_val(&tmp, find_min(tmp)));
	*head = sorted_list;
}

int	is_cmdvalid(char *cmd)
{
	const int	cmdlen = ft_strlen(cmd);

	if (ft_strncmp(cmd, "sa", cmdlen) == 0
		|| ft_strncmp(cmd, "sb", cmdlen) == 0
		|| ft_strncmp(cmd, "ss", cmdlen) == 0
		|| ft_strncmp(cmd, "pa", cmdlen) == 0
		|| ft_strncmp(cmd, "pb", cmdlen) == 0
		|| ft_strncmp(cmd, "ra", cmdlen) == 0
		|| ft_strncmp(cmd, "rb", cmdlen) == 0
		|| ft_strncmp(cmd, "rr", cmdlen) == 0
		|| ft_strncmp(cmd, "rra", cmdlen) == 0
		|| ft_strncmp(cmd, "rrb", cmdlen) == 0
		|| ft_strncmp(cmd, "rrr", cmdlen) == 0)
		return (1);
	return (0);
}

void	apply_instructions(t_data *data)
{
	char	*cmd;

	cmd = get_next_line(0);
	if (cmd)
		cmd[ft_strlen(cmd) - 1] = 0;
	while (cmd && *cmd)
	{
		if (!is_cmdvalid(cmd))
		{
			free(cmd);
			free_data(data);
			error();
		}
		make_step(data, cmd);
		free(cmd);
		cmd = get_next_line(0);
		if (cmd)
			cmd[ft_strlen(cmd) - 1] = 0;
	}
	if (cmd)
		free(cmd);
}

int	is_same(t_list *list1, t_list *list2)
{
	while (list1 && list2 && list1->val == list2->val)
	{
		list1 = list1->next;
		list2 = list2->next;
		if (!list1 && !list2)
			return (1);
		if (!list1 || !list2)
			return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		silence;
	t_data	*data;

	if (argc < 2)
		return (0);
	data = parser(argv + 1, argc - 1);
	data->display_steps = 0;
	apply_instructions(data);
	if (is_sorted(data->list_a) && data->len_b == 0)
		silence = write(1, "OK!\n", 4);
	else
		silence = write(1, "KO!\n", 4);
	free_data(data);
	if (silence)
		return (0);
	return (0);
}
