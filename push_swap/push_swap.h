/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:50:43 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 17:22:14 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_nvr
{
	int				stack;
	int				mov_a;
	int				mov_b;
	int				mark;
	struct s_nvr	*next;
}	t_nvr;

typedef struct s_var
{
	int		a;
	int		b;
	int		x;
	int		jl;
	char	*str;
	int		*tab;
	t_nvr	*indexes;
	int		k;
	int		j;
	int		min;
	int		count;
	int		lis;
	t_nvr	*sa;
	t_nvr	*sb;
	t_nvr	*sorts;
	t_nvr	*last;
	t_nvr	*reg;
	t_nvr	*node;
	int		big;
	int		head;
}	t_var;

typedef struct s_norm
{
	int		a;
	int		min;
	int		big;
	int		size;
	t_nvr	*ss;
	t_nvr	*reg;
	t_nvr	*last;
	t_nvr	*head;
	t_nvr	*head1;
	int		kk;
}	t_norm;

typedef struct s_mix
{
	int		a;
	int		min;
	int		big;
	int		size;
	t_nvr	*ss;
	t_nvr	*reg;
	t_nvr	*last;
}	t_mix;

typedef struct s_lis
{
	t_nvr	*indxs;
	int		*tab;
	int		*arr;
}	t_lis;

typedef struct s_var2
{
	int		x;
	int		y;
	t_nvr	*node;
	t_nvr	*reg;
	t_nvr	*last;
	t_nvr	*indexs;
	int		*art;
	t_nvr	*list;
	int		j;
	int		a;
}	t_var2;

long long		ft_atoi(const char *str);
int				ft_free(char **strs);
void			ft_lstdelone(t_nvr **lst);
t_nvr			*final_mov(t_nvr **sta, t_nvr **stb);
char			**ft_split(char const *s, char c);
int				ft_strcmp(char *s1, char *s2);
void			push_swap(char **sot, int cnt);
void			check_case(char **tar);
int				check_sort(t_nvr *t, char **strs);
char			*ft_strjoin(int size, char **strs, char *sep);
int				find_big(int *arr, int size);
void			ft_save(t_nvr **root, int *item, int mark, int elem);
t_nvr			*ft_lstnew(int *val);
int				ft_lstsize(t_nvr *lst);
void			insert(t_nvr **root, int item);
void			ft_lstadd_front(t_nvr **lst, t_nvr *new);
void			swap_a_b(int *a, int *b, char c);
void			push_a_b(t_nvr **a, t_nvr **b, char c);
void			rotate_a_b(t_nvr **a, char c);
void			reverse_rotate_a_b(t_nvr **a, char c);
void			sw_ss(int *a, int *b, int *x, int *y);
void			rotate_rr(t_nvr **a, t_nvr **b);
void			reverse_rotate_rrr(t_nvr **a, t_nvr **b);
t_nvr			*link_lst(t_nvr **head);
void			sort_stacks(t_nvr **sta, t_nvr **stb, t_nvr **lis);
void			check_and_rotate(t_nvr **sta, t_nvr **stb, int kk, char c);
t_nvr			*count_mv(t_nvr *sta, t_nvr *stb);
int				half(t_nvr *sta, int kk);
t_nvr			*ft_lstlast(t_nvr *lst);
t_nvr			*ft_lis(t_nvr *lis, int size, int min, t_nvr *last);
int				find_big_one(t_nvr *arr);
int				find_small(t_nvr *arr);
void			return_to_sta(t_nvr **sta, t_nvr **stb);
void			d_link(t_nvr **stack, t_nvr *last, t_nvr *reg);
t_nvr			*find_best_mov(t_nvr *all);
int				hi(t_nvr *sta, int kk);
void			check_a(t_nvr **sta, int kk, char c);
int				hi(t_nvr *sta, int kk);
int				count_stb(t_nvr *stb, int elem, int *mark);
int				count_sta(t_nvr *taa, int elem, int size, int *mark);

#endif
