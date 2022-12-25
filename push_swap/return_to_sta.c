/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_sta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:28:39 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/25 17:09:20 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	hi(t_nvr *sta, int kk)
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

void	hello(t_nvr **sta, int kk, char c)
{
	int	jbl;

	jbl = hi(*sta, kk);
	while (1)
	{
		if ((*sta)-> stack == kk)
			break ;
		if (jbl == 1)
			rotate_a_b(&*sta, c);
		if (jbl == 0)
			reverse_rotate_a_b(&*sta, c);
	}
}

void	final_push(t_nvr **sta, t_nvr **stb, int kk, char c)
{
	int	jbl;

	jbl = hi(*sta, kk);
	while (1)
	{
		if ((*sta)-> stack == kk)
			break ;
		if (jbl == 1)
			rotate_a_b(&*sta, c);
		if (jbl == 0)
			reverse_rotate_a_b(&*sta, c);
	}
	push_a_b(&*stb, &*sta, 'b');
}

int	count_in(t_nvr *taa, int elem, int size, t_nvr *reg)
{
	t_norm	n;

	n.ss = taa;
	n.a = -1;
	n.min = find_small(taa);
	n.big = find_big_one(taa);
	n.last = link_lst(&taa);
	while (++n.a < size)
	{
		if (elem > n.big || elem < n.min
			|| (n.ss-> stack < elem && n.ss-> next -> stack > elem))
		{
			if (elem < n.min)
				n.a = n.min;
			if (elem > n.big)
				n.a = n.big;
			if (n.ss-> stack < elem && n.ss-> next -> stack > elem)
				n.a = n.ss-> next -> stack;
			break ;
		}
		n.ss = n.ss-> next;
	}
	d_link(&taa, n.last, reg);
	return (n.a);
}

void	return_to_sta(t_nvr **sta, t_nvr **stb)
{
	t_nvr	*indexs;
	int		elem;
	int		place;
	int		a;

	a = 0;
	while (*stb)
	{
		if ((*stb)-> next == NULL)
			elem = (*stb)-> stack;
		else
		{
			indexs = count_mv(*sta, *stb);
			elem = find_best_mov(&indexs);
		}
		hello(&*stb, elem, 'b');
		place = count_in(*sta, elem, ft_lstsize(*sta),*sta);
		final_push(&*sta, &*stb, place, 'a');
		a++;
	}
}
