/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:07:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/04 18:07:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define S_THRESHOLD 7
# define MIN(a, b) a > b ? a : b
# define MAX(a, b) a > b ? b : a

typedef struct s_list
{
	int val;
	int score;
	struct s_list *next;
} t_list;

typedef struct s_data
{
	t_list	*list_a;
	t_list	*list_b;

	int		i;
	int		j;
	int		max;
	int		min;
	int		len_a;
	int		len_b;
} t_data;

t_data	*new_data(void);
void	free_data(t_data *data);

void	swap(t_list **head);
void	push(t_list **fhead, t_list **shead, int *flen, int *slen);
void	reverse(t_list **nhead);
void	reverse_rotate(t_list **head);
void	make_step(t_data *data, char *name);

t_list	*new_list(int val);
void	free_list(t_list *list);
void	push_back(t_list **head, t_list *new_elem);
void	push_front(t_list **head, t_list *new_elem);
t_list	*pop_head(t_list **head);
void	print_list(t_list *head);

void	rotate(t_data *data, int rotate_pnt);
int		is_rotated(t_list *list);
int		is_sorted(t_list *list);
int		find_rotatepnt(t_list *list);
void 	sort_small(t_data *data);
void	sort_medium(t_data *data);
void	sort_large(t_data *data);

int	ft_atoi(const char *s);
int	ft_strncmp(const char *s1, const char *s2, int n);

#endif