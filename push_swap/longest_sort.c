/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/15 21:38:35 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void     find_longest(t_nvr *lst)
{
    int min;
    int count;
    //t_nvr *tmp;
    
    min = lst -> stack;
    count = 0;
    // tmp = lst;
    // while(lst)
    // {
    //     printf("|%d|", lst -> stack);
    //     lst = lst -> next;
    // }
    // lst = tmp;
    while(lst != NULL)
    {
        if(lst -> stack > min)
            count++;
        lst = lst -> next;
    }
    printf("%d", count);
}