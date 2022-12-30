/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:45:37 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/30 15:53:30 by abelfany         ###   ########.fr       */
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
	if (a <= size / 2)
		return (1);
	else
		return (0);
}

int	count_stb(t_nvr *stb, int elem, int *mark)
{
	int	a;
	int	size;

	size = ft_lstsize(stb);
	a = 0;
	while (a < size)
	{
		if (stb-> stack == elem)
			break ;
		stb = stb-> next;
		a++;
	}
	if (a > size / 2)
	{
		a = size - a;
		*mark += 1;
	}
	return (a);
}

int	count_sta_utils(t_nvr *sta, int elem, int *mimx, int size)
{
	int	a;
	int	min;
	int	big;

	a = -1;
	min = mimx[0];
	big = mimx[1];
	while (++a < size)
	{
		if (sta-> stack == min && elem < min)
			break ;
		if (sta -> stack == big && elem > big)
		{
			a++;
			break ;
		}
		if (sta-> stack < elem && sta-> next -> stack > elem)
		{
			a++;
			break ;
		}
		sta = sta -> next;
	}
	return (a);
}

int	count_sta(t_nvr *taa, int elem, int size, int *mark)
{
	t_mix	m;
	int		mimx[2];
	int		a;

	m.reg = taa;
	mimx[0] = find_small(taa);
	mimx[1] = find_big_one(taa);
	m.last = link_lst(&taa);
	a = count_sta_utils(taa, elem, mimx, size);
	if (a > size / 2)
	{
		a = size - a;
		*mark += 1;
	}
	return (d_link(&taa, m.last, m.reg), a);
}

t_nvr	*final_mov(t_nvr **sta, t_nvr **stb)
{
	int		mark;
	t_nvr	*head;
	t_nvr	*save;
	int		a[2];

	mark = 0;
	head = *stb;
	save = NULL;
	while (head)
	{
		a[0] = count_sta(*sta, head-> stack, ft_lstsize(*sta), &mark);
		a[1] = count_stb(*stb, head-> stack, &mark);
		ft_save(&save, a, mark, head-> stack);
		mark = 0;
		head = head -> next;
	}
	return (save);
}
