/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_sta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:28:39 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/23 21:27:44 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int hi(t_nvr *sta, int kk)
{
    int size;
    t_nvr *head;
    int a = 0;
    //kk = 0;
    head = sta;
    size = ft_lstsize(sta);
    while(a < size)
    {
        if(sta -> stack == kk)
            break;
        a++;
        sta = sta -> next;
    }
    sta = head;
    if(a < size / 2)
        return 1;
    else
        return 0;
}
void hello(t_nvr **sta, int kk, char c)
{
   int jbl;
    
    jbl = hi(*sta,kk);
    while(1)
    {
        if((*sta) -> stack == kk)
            break;
        if(jbl == 1)
           rotate_a_b(&*sta, c);
        if(jbl == 0)
            reverse_rotate_a_b(&*sta, c);
    }
}

void final_push(t_nvr **sta, t_nvr **stb, int kk, char c)
{
   int jbl;
    
    jbl = hi(*sta,kk);
    while(1)
    {
        if((*sta) -> stack == kk)
            break;
        if(jbl == 1)
           rotate_a_b(&*sta, c);
        if(jbl == 0)
            reverse_rotate_a_b(&*sta, c);
    }
    push_a_b(&*sta, &*stb, c);
}
int count_in(t_nvr *taa, int elem)
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
            return (taa -> next -> stack);
        if(taa -> stack == min && elem < min)
            break;
        if(taa -> stack == big && elem > big)
            break;
        a++;
        taa = taa -> next;
    }
    taa = reg;
    while (taa -> stack != last -> stack)
        taa = taa -> next;
    taa -> next = NULL;
    taa = reg;
    return 0;
}
void    return_to_sta(t_nvr **sta, t_nvr **stb, int elem)
{
    hello(&*stb,elem,'p');
    int place = count_in(*sta,elem);
    final_push(&*stb,&*sta,place,'p');
    
}