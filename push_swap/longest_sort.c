/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/20 16:05:01 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int long_inc_subs(t_nvr **lst, t_nvr *add, t_nvr **all)
{
    t_var x;

    x.reg = *lst;
    while ((*lst) -> stack != add -> stack)
        (*lst) = (*lst) -> next;
    (*lst) -> next = NULL;
    *lst = x.reg;
    x.big = (*all) -> stack;
    x.head = (*all) -> next -> stack;
    while ((*all) -> next -> next)
    {
        x.node = (*all);
        while (x.node -> next -> next)
        {
            if (x.node -> next -> next -> stack > x.big)
            {
                x.big = x.node -> next -> next -> stack;
                x.head = x.node -> next -> next -> next -> stack;
            }
            x.node = x.node -> next -> next;
        }
        (*all) = (*all) -> next -> next;
    }
    return x.head;
}

int	ft_lstsize(t_nvr *lst)
{
	int	a;

	a = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
        a++;
    }
	return (a);
}

t_nvr *all_sorts(t_nvr *ldb,int min, int a)
{
    insert(&ldb,a);
    insert(&ldb,min);
    return ldb;
}
t_nvr   *link_lst(t_nvr **head)
{
    t_nvr *first;
    t_nvr *last;

    first = *head;
    last = *head;
    while(last -> next != NULL)
        last = last -> next;
    last -> next = first;
    return (last);
}
int     find_longest(t_nvr *lst)
{
    t_var x;
    
    x.v = ft_lstsize(lst);
    x.last = link_lst(&lst);
    x.count = 1;
    x.j = 0;
    x.sa = lst;
    x.sorts = NULL;
    while(++x.j <= x.v)
    {
        x.min = x.sa -> stack;
        x.k = 0;
        x.sb = x.sa -> next;
        while(++x.k <= x.v)
        {
            if(x.sb -> stack > x.min)
            {
                x.count++;
                x.min = x.sb -> stack;
            }
            x.sb = x.sb -> next;
        }
        x.sorts = all_sorts(x.sorts,x.sa -> stack,x.count);
        x.count = 1;
        x.sa = x.sa -> next;
    }
    x.jl = long_inc_subs(&lst, x.last, &x.sorts);
    return x.jl;
}