/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:50:43 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/16 20:59:37 by abelfany         ###   ########.fr       */
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
	char *str;
    int *tab;
    /*---*/
    int v;
    int k;
    int j;
    int min;
    int count;
    t_nvr *sa;
    t_nvr *sb;
    t_nvr *sorts;
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
void            find_longest(t_nvr *lst);


/**----------------------tests----------------------*/
        void test_instra(t_nvr *a, t_nvr *b);     
/*                                                  */
/*                                                  */
/*                                                  */
/*----------------------tests-----------------------*/
#endif