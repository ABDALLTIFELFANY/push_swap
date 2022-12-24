/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:00:51 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/24 11:43:32 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void count_in_stb(t_nvr *stb, int elem, int *count)
{
    int a = 0;
    int size = ft_lstsize(stb);
    while(a < size)
    {
        if(stb -> stack == elem)
            break;
        stb = stb -> next;
        a++;
    }
    if(a > size / 2)
        *count += size - a;
    else
        *count += a;
}
int count_in_sta(t_nvr *taa, t_nvr *tab, int elem)
{
    int a = 0;
    t_nvr *ss = taa;
    taa = ss;
    int min = find_small(taa);
    int big = find_big_one(taa);
    t_nvr *reg = taa;
    int size = ft_lstsize(taa);
    t_nvr *last = link_lst(&taa);
    while(a < size)
    {
        if(taa -> stack < elem && taa -> next -> stack > elem)
        {
            a++;
            break;
        }
        if(taa -> stack == min && elem < min)
            break;
        if(taa -> stack == big && elem > big)
            break;
        a++;
        taa = taa -> next;
    }
    if(a > size / 2)
        a = size - a;
    count_in_stb(tab,elem,&a);
    taa = reg;
    while (taa -> stack != last -> stack)
        taa = taa -> next;
    taa -> next = NULL;
    taa = reg;
    return a;
}
t_nvr *moves_place(t_nvr *ldb,int min, int a)
{
    insert(&ldb,min);
    insert(&ldb,a);
    return ldb;
}
t_nvr *count_mv(t_nvr *sta, t_nvr *stb)
{
    int val;
    t_nvr *head;
    t_nvr *save = NULL;
    t_nvr *head1;
    head = sta;
    head1 = stb;
    val = count_in_sta(head,stb, head1 -> stack);
    save = moves_place(save,val,head1 -> stack);
    head1 = head1 -> next;
    while(head1)
    {
        val = count_in_sta(head,stb,head1 -> stack);
        save = moves_place(save,val,head1 -> stack);
        head1 = head1 -> next;
    }
    return save;
}