/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:07:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/11 03:20:17 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# define S_THRESHOLD 7

typedef struct s_list
{
	int				val;
	int				score;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	t_list	*list_a;
	t_list	*list_b;

	int		i;
	int		j;
	int		med;
	int		max;
	int		min;
	int		flag;
	int		len_a;
	int		len_b;
}	t_data;

t_data	*new_data(void);
void	free_data(t_data *data);

void	swap(t_list **head);
void	push(t_list **fhead, t_list **shead, int *flen, int *slen);
void	reverse(t_list **nhead);
void	reverse_rotate(t_list **head);
void	make_step(t_data *data, char *name);

t_list	*new_list(int val);
int		lstlen(t_list *list);
void	free_list(t_list *list);
void	push_back(t_list **head, t_list *new_elem);
void	push_front(t_list **head, t_list *new_elem);
t_list	*pop_head(t_list **head);
t_list	*copy_list(t_list *list);
t_list	*copy_sublist(t_list *list, int start, int end);
t_list	*pop_val(t_list **head, int val);
int		find_max(t_list *list);
int		find_med(t_list *list);
int		find_min(t_list *list);

t_list	*array_tolist(char **array);
void	free_array(char **array);
int		arrlen(char **ptr);

int		valid(char **array);
int		duplicates(t_list *list);
void	rotate(t_data *data, int rotate_pnt);
int		is_rotated(t_list *list);
int		is_sorted(t_list *list);
int		find_rotatepnt(t_list *list);
void	make_rotation(t_data *data);
void	sort_small(t_data *data);
void	sort_main(t_data *data);

int		ft_atoi(const char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	error(void);

#endif