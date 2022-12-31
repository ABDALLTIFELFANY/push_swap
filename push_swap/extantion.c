/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extantion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:20:05 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/30 19:35:30 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half(t_nvr *sta, int kk)
{
	int		size;
	t_nvr	*head;
	int		a;

	a = 0;
	head = sta;
	size = ft_lstsize(sta);
	while (a < size)
	{
		if (sta-> stack == kk)
			break ;
		a++;
		sta = sta-> next;
	}
	sta = head;
	if (a < size / 2)
		return (1);
	else
		return (0);
}

t_nvr	*ft_lstlast(t_nvr *lst)
{
	if (!lst)
		return (NULL);
	while (lst-> next != NULL)
		lst = lst-> next;
	return (lst);
}

int	find_big_one(t_nvr *arr)
{
	int	big;

	big = arr -> stack;
	while (arr)
	{
		if (arr-> stack > big)
			big = arr-> stack;
		arr = arr-> next;
	}
	return (big);
}

int	find_small(t_nvr *arr)
{
	int	min;

	min = arr-> stack;
	while (arr)
	{
		if (arr-> stack < min)
			min = arr-> stack;
		arr = arr-> next;
	}
	return (min);
}
