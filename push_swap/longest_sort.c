/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/16 21:02:27 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_nvr *find_big_number(t_nvr *lst)
// {
//     int big = lst -> next -> stack;
//     printf("%d", a);
//     while(lst != NULL)
//     {
//         if(lst -> stack > big)
//             big = 
//     }
// }

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

t_nvr *all_sorts(t_nvr *ldb, int min, int a)
{
    insert(&ldb,min);
    insert(&ldb,a);
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
    printf("%d", last -> stack);
    return (last);
}
// }
void    find_longest(t_nvr *lst)
{
    t_var x;
    t_nvr *last;
    
    x.v = ft_lstsize(lst);
    last = link_lst(&lst);
    x.count = 1;
    x.j = 0;
    x.sa = lst;
    x.sorts = NULL;
    while(x.j < x.v)
    {
        x.min = x.sa -> stack;
        x.k = x.j + 1;
        x.sb = x.sa -> next;
        while(x.k < x.v)
        {
            if(x.sb -> stack > x.min)
            {
                x.count++;
                x.min = x.sb -> stack;
            }
            x.sb = x.sb -> next;
            x.k++;
        }
        //x.sorts = all_sorts(x.sorts,x.u -> stack,x.count);
        printf("%d\n", x.count);
        x.count = 1;
        x.sa = x.sa -> next;
        x.j++;
    }
    //find_big_number(x.sorts);
    while(x.sorts)
    {
        printf("%d\n", x.sorts -> stack);
        x.sorts = x.sorts -> next;
    }
}