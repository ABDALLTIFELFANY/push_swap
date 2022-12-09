/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:43:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/09 19:06:45 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    insert(t_nvr **root, int item)
{
    t_nvr   *temp;
    t_nvr   *ptr;

    temp = malloc(sizeof(t_nvr));
    temp->stack = item;
    temp->next = NULL;
    if (*root == NULL)
        *root = temp;
    else 
    {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}