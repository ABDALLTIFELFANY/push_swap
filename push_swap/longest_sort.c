/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:26:23 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 16:18:43 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	long_inc_subs(t_nvr **lst, t_nvr *add, t_nvr **all, int *big)
{
	t_var	x;

	x.reg = *lst;
	while ((*lst)-> stack != add-> stack)
		(*lst) = (*lst)-> next;
	(*lst)-> next = NULL;
	*lst = x.reg;
	*big = (*all)-> stack;
	x.head = (*all)-> next -> stack;
	while ((*all)-> next -> next)
	{
		x.node = (*all);
		while (x.node-> next -> next)
		{
			if (x.node-> next -> next -> stack > *big)
			{
				*big = x.node-> next -> next -> stack;
				x.head = x.node-> next -> next -> next -> stack;
			}
			x.node = x.node-> next -> next;
		}
		(*all) = (*all)-> next -> next;
	}
	return (x.head);
}

int	ft_lstsize(t_nvr *lst)
{
	int	a;

	a = 0;
	while (lst != NULL)
	{
		lst = lst-> next;
		a++;
	}
	return (a);
}

t_nvr	*all_sorts(t_nvr *ldb, int min, int a)
{
	ldb = NULL;
	insert(&ldb, a);
	insert(&ldb, min);
	return (ldb);
}

t_nvr	*link_lst(t_nvr **head)
{
	t_nvr	*first;
	t_nvr	*last;

	first = *head;
	last = *head;
	while (last-> next != NULL)
		last = last-> next;
	last -> next = first;
	return (last);
}

int	find_longest(t_nvr *lst, int *lenght, int size)
{
	t_var	x;

	x.last = link_lst(&lst);
	x.count = 1;
	x.j = 0;
	while (++x.j <= size)
	{
		x.min = lst-> stack;
		x.k = 0;
		x.sb = lst-> next;
		while (++x.k <= size)
		{
			if (x.sb -> stack > x.min)
			{
				x.count++;
				x.min = x.sb-> stack;
			}
			x.sb = x.sb-> next;
		}
		x.sorts = all_sorts(x.sorts, lst-> stack, x.count);
		x.count = 1;
		lst = lst-> next;
	}
	*lenght = x.count;
	return (long_inc_subs(&lst, x.last, &x.sorts, &x.count));
}
