/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:12:19 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/04 19:12:19 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void error(void)
{
	write(1, "Error\n", 7);
	exit(0);
}

t_data *parser(char **argv, int argc)
{
	int i;
	t_list *tmp;
	t_data *data;

	data = new_data();
	i = -1;
	while (++i < argc)
	{
		tmp = new_list(ft_atoi(argv[i]));
		push_back(&(data->list_a), tmp);
	}
	data->len_a = argc;
	return (data);
}


int main(int argc, char **argv)
{
	t_data *data;
	char input[4];

	data = parser(argv + 1, argc - 1);
	read(0, input, 4);
	while (1)
	{
		if (ft_strncmp(input, "zzz", 3) == 0)
			break ;
		make_step(data, input);
		printf("a: ");
		print_list(data->list_a);
		printf("b: ");
		print_list(data->list_b);
		read(0, input, 4);
	}
	return (0);
}