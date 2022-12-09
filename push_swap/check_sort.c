/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:40:12 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/09 16:18:22 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_nvr *t)
{
    int j;

    j = 0;
    while(t != NULL && t -> next)
    {  
        if((t -> stack) > (t -> next -> stack))
            j = 1;
        t = t -> next;
    }
    if(j == 0)
        exit(0);
    return 1;
}   