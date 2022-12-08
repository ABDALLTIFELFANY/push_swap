/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/07 15:44:16 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_min(int *tab, int size)
{
    int a = -1;
    int min = tab[0];
    while(++a < size)
        if(tab[a] < min)
            min = tab[a];
        return min;   
}
void	sortadd(int *tab, int size)
{
    // int a = 0;
    // int b = 0;
	int min = find_min(tab, size);
    printf("%d", min);
    // int *tst;
    // while(a < size)
    // {
    //     if(tab[a] > min)
    //         a++;
    //     tst[b++] = tab[a];
    //     a++;
    // }
}
// int main()
// {
//     int tab[] = {14, 48, 78, 45, 71, 8, 9, 3};
//     int size  = sizeof(tab)/sizeof(tab[0]);
//     check_sort(tab, size);
// }