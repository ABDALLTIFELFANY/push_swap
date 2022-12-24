/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:50:43 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/24 13:59:05 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type));

typedef struct s_nvr
{
    int stack;
    struct s_nvr *next;
}   t_nvr;

typedef struct s_var
{
    int a;
    int b;
	int x;
	int jl;
	char *str;
    int *tab;
    t_nvr *indexes;
    /*find_longest*/
    int v;
    int k;
    int j;
    int min;
    int count;
    int lis;
    t_nvr *sa;
    t_nvr *sb;
    t_nvr *sorts;
    t_nvr *last;
    /*long_inc_subs*/
    t_nvr *reg;
    t_nvr *node;
    int big; 
    int head;  
}	t_var;


# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

long long       ft_atoi(const char *str);
char            **ft_split(char const *s, char c);
int             ft_strcmp(char *s1, char *s2);
void            push_swap(char **sot, int cnt);
void            check_case(char **tar);
int             check_sort(t_nvr *t);
char            *ft_strjoin(int size, char **strs, char *sep);
/*-----------------|\|-------------------*/
t_nvr	        *ft_lstnew(int *val);
int             ft_lstsize(t_nvr *lst);
void            insert(t_nvr **root, int item);
void            ft_lstadd_front(t_nvr **lst, t_nvr *new);
/*-----------------|\|-------------------*/
void            swap_a_b(int *a, int *b, char c);
void            push_a_b(t_nvr **a, t_nvr **b, char c);
void            rotate_a_b(t_nvr **a, char c);
void            reverse_rotate_a_b(t_nvr **a, char c);
void            swap_ss(int *a, int *b, int *x, int *y);
void            rotate_rr(t_nvr **a, t_nvr **b);
void	        reverse_rotate_rrr(t_nvr **a, t_nvr **b);
/*-----------------algorithm-------------------*/
int             find_longest(t_nvr *lst, int *lenght);
t_nvr           *link_lst(t_nvr **head);
void             sort_stacks(t_nvr **sta, t_nvr **stb, t_nvr **lis);
//void          ft_ft(t_nvr **sta, t_nvr **stb, t_nvr *index, int kk);
void            check_and_rotate(t_nvr **sta, t_nvr **stb, int kk,char c);
t_nvr           *find_who_p_b(t_nvr *sta, int kk);
void            find_it(t_nvr **tab , int kk, int size);
void            sort_a(t_nvr **sta, t_nvr **stb,int kk);
t_nvr           *count_mv(t_nvr *sta, t_nvr *stb);
int             half(t_nvr *sta, int kk);
t_nvr	        *ft_lstlast(t_nvr *lst);
int             find_big_one(t_nvr *arr);
int             find_small(t_nvr *arr);
void            return_to_sta(t_nvr **sta, t_nvr **stb);
int             find_best_mov(t_nvr **all);
int hi(t_nvr *sta, int kk);


/**----------------------tests----------------------*/
        void test_instra(t_nvr *a, t_nvr *b);     
/*                                                  */
/*                                                  */
/*                                                  */
/*----------------------tests-----------------------*/
#endif