/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:40:12 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/05 17:08:29 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_sort(int *tab, int size)
{
    int a;
    int b;
    int j;
    
    a = 0;
    b = a + 1;
    j = 0;
    while(a < size && b < size)
    {  
        if(tab[a] > tab[b])
            j = 1;
        a++;
        b++;
    }
    if(j == 0)
        exit(0);
}   