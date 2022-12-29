/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:59:17 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/29 15:51:46 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) b;
	while (len--)
		*ptr++ = (unsigned char) c;
	return (b);
}

int	find_big(int *arr, int size)
{
	int	big;
    int x = 1;

	big = arr[0];
	while (x < size)
	{
		if (arr[x] > big)
			big = arr[x];
		x++;
	}
	return (big);
}

void gg(t_nvr **lst, int inx)
{
	insert(lst, inx);
}

t_nvr *longest_inc(int *tab, int *arr, int lis, t_nvr *head)
{
    int *art;
    t_nvr *list = NULL;
    int x;
    int a;

    x = 0;
    a = 0;
    while(tab[x] != lis)
        x++;
    art = malloc(sizeof(int) * lis);
    while(a < lis)
    {
        art[a] = x;
        x = arr[x];
        a++;
    }
    x = 0;
    while(--a > -1)
    {
        while(x < art[a])
        {
            head = head -> next;
            x++;
        }
        gg(&list,head -> stack);
    }
    return (list);
}
t_nvr *ft_lis(t_nvr *lis, int size)
{
    t_nvr *head;
    t_nvr *indxs;
    t_nvr *reg = lis;
    t_nvr *last;
    t_nvr *jbl;
    int min = find_small(lis);
    last = link_lst(&lis);
    int i = 0;
    int a = 0;
    int j;
    int *tab = malloc(sizeof(int) * size);
    int *arr = malloc(sizeof(int) * size);
    while(a < size)
        tab[a++] = 1;
    arr = ft_memset(arr,0,size);
    while(lis -> stack != min)
        lis = lis -> next;
    head = lis;
    while(i < size)
    {
        j = 0;
        while(j < i)
        {
            if(jbl -> stack < lis -> stack && tab[j] + 1 >= tab[i])
            {
                tab[i] = tab[j] + 1;
                arr[i] = j;
            }
            jbl = jbl -> next;
            j++;
        }
        lis = lis -> next;
        jbl = head;
        i++;
    }
    indxs = longest_inc(tab,arr,find_big(tab,size),head);
    d_link(&lis,last,reg);
    return(indxs);
}