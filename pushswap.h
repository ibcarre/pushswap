/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:32:33 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:43:00 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_l
{
	int			content;
	struct s_l	*next;
}				t_l;

t_l				*ft_lstnew(int value);
void			ft_lstadd_back(t_l **list, t_l *new);
long			ft_atoi(const char *str);
int				ft_isdigit(int c);
char			**ft_split(char const *s, char c);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_freelst(t_l *head);
int				check_int(char *nb);
int				check_dup(t_l *head);
int				ft_create_stack(char **nb, t_l **stack_a);
void			ft_swap(t_l **stack);
void			ft_lstadd_front(t_l **list, t_l *new);
void			push(t_l **stack, t_l **stack_d);
void			ft_rot(t_l **stack);
void			ft_rot_d(t_l **stack, t_l **stack_d);
void			ft_revrot(t_l **stack);
t_l				*ft_last(t_l *new);
void			ft_revrot_d(t_l **stack, t_l **stack_d);
int				len_lst(t_l *stack);
int				get_cost(int len, int idx);
void			swap_a(t_l **stack_a);
void			swap_b(t_l **stack_b);
void			push_a(t_l **stack_a, t_l **stack_b);
void			push_b(t_l **stack_b, t_l **stack_a);
void			rot_a(t_l **stack_a);
void			rot_b(t_l **stack_b);
void			rot_d(t_l **stack_a, t_l **stack_b);
void			revrot_a(t_l **stack_a);
void			revrot_b(t_l **stack_b);
void			revrot_d(t_l **stack_a, t_l **stack_b);
void			sort_two(t_l **stack);
void			sort_three(t_l **stack);
void			sort(t_l **stack_a, t_l **stack_b);
int				max(int a, int b);
int				min(int a, int b);
int				get_cheapest_b(t_l *stack_a, t_l *stack_b);
int				get_max_idx(t_l *stack);
int				get_min_idx(t_l *stack);
int				get_min_val(t_l *stack);
int				get_corr_b(int val, t_l *stack_b);
int				get_max_val(t_l *stack);
size_t			ft_strlen(const char *str);
int				is_ordered(t_l *stack);
t_l				*skip_to_min(t_l *stack_a, int *i);
void			change_one(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b);
int				get_val(int idx, t_l *stack);
int				get_way(int idx_a, t_l *stack_a, int idx_b, t_l *stack_b);
int				same_half(int idx_a, t_l *stack_a, int idx_b, t_l *stack_b);
void			revrotate_both(int idx_a, t_l **stack_a, int idx_b,
					t_l **stack_b);
void			rotate_both(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b);

#endif
