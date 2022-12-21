/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:24:33 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/21 22:28:58 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int half(t_nvr *sta, int kk)
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
    return 0;
}
void check_and_rotate(t_nvr **sta, t_nvr **stb, int kk, char c)
{
   int jbl;
    
    jbl = half(*sta,kk);
    while(1)
    {
        if((*sta) -> stack == kk)
            break;
        if(jbl == 1)
           rotate_a_b(&*sta, c);
        else
            reverse_rotate_a_b(&*sta, c);
    }
    push_a_b(&*sta, &*stb, c);
}
t_nvr *sort_stacks(t_nvr **sta, t_nvr **stb, t_nvr *lis)
{
    t_nvr *head;
    t_nvr *head1;
    int kk;
    
    head = *sta;
    while(head)
    {
        head1 = lis;
        while(head1)
        {
            if(head -> stack == head1 -> stack)
            {
                kk = 1;
                break;
            }
            head1 = head1 -> next;   
        }
        if(kk == 0)
        {
            check_and_rotate(&*sta,&*stb,head -> stack,'a');
            kk = find_longest(*sta);
            //printf("----%d\n", kk);
            lis = find_who_p_b(*sta,kk);
            head = *sta;
        }
        else
            head = head -> next;
        
        kk = 0;
    }
    return head;
}
void find_it(t_nvr **tab , int kk, int size)
{
    int x = 0;
    while(x < size)
    {
        if((*tab) -> stack == kk){
            (*tab) = (*tab) -> next;
            break;
        }
        (*tab) = (*tab) -> next;
        x++;
    }
}
t_nvr *index_s(t_nvr *lst, int inx)
{
    insert(&lst,inx);
    return lst;
}
t_nvr *find_who_p_b(t_nvr *sta, int kk)
{
    t_nvr *node;
    t_nvr *last;
    t_nvr *reg;
    int size;
    int x;
    int y;

    t_nvr *indexs = NULL;
    size = ft_lstsize(sta);
    x = 0;
    last = link_lst(&sta);
    indexs = index_s(indexs,kk);
    reg = sta;
    while(x < size)
    {
        node = sta;
        find_it(&node,kk,size);
        y = x + 1;
        while(y < size)
        {
            if(node -> stack > kk)
            {
                indexs = index_s(indexs,node -> stack);
                kk = node -> stack;
                break;
            }
            node = node -> next;
            y++;
        }
        sta = sta -> next;
        x++;
    }
    reg = sta;
    while (sta -> stack != last -> stack)
        sta = sta -> next;
    sta -> next = NULL;
    sta = reg;
    return indexs;
}
