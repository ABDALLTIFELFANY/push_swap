/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:20:05 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/23 09:20:41 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nvr	*ft_lstlast(t_nvr *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

int find_big_one(t_nvr *arr)
{
    int big;
 
    big = arr -> stack;
    while (arr)
    {
        if(arr -> stack > big)
            big = arr -> stack;
        arr = arr -> next;   
    }
    return (big);
}

int find_small(t_nvr *arr)
{
    int min;
 
    min = arr -> stack;
    while (arr)
    {
        if(arr -> stack < min)
            min = arr -> stack;
        arr = arr -> next;   
    }
    return (min);
}