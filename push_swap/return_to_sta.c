/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_sta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:28:39 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/31 11:06:42 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_elem_place(t_nvr *taa, int elem, int size)
{
	t_mix	m;
	int		ret;

	m.reg = taa;
	m.a = -1;
	m.min = find_small(taa);
	m.big = find_big_one(taa);
	m.last = link_lst(&taa);
	while (++m.a < size)
	{
		if ((taa-> stack < elem && taa-> next -> stack > elem)
			|| elem < m.min || elem > m.big)
		{
			ret = taa-> next -> stack;
			if (elem < m.min || elem > m.big)
				return (d_link(&taa, m.last, m.reg), m.min);
			return (d_link(&taa, m.last, m.reg), ret);
		}
		taa = taa -> next;
	}
	if (m.a > size / 2)
		m.a = size - m.a;
	d_link(&taa, m.last, m.reg);
	return (m.a);
}

void	prepar_a(t_nvr **sta, t_nvr *elem)
{
	int	a;
	int	gg;
	int	x;

	elem -> mov_a = count_sta(*sta, elem -> stack, ft_lstsize(*sta), &a);
	if (elem -> mov_a == 0)
		return ;
	else
	{
		gg = find_elem_place(*sta, elem -> stack, ft_lstsize(*sta));
		a = hi(*sta, gg);
		x = elem -> mov_a;
		while (--x > -1)
		{
			if (a == 1)
				rotate_a_b(sta, 'a');
			if (a == 0)
				reverse_rotate_a_b(sta, 'a');
		}
	}
}

void	prepar_b(t_nvr **stb, t_nvr *elem)
{
	int	a;
	int	x;

	elem -> mov_b = count_stb(*stb, elem -> stack, &a);
	if (elem -> mov_b == 0)
		return ;
	else
	{
		a = hi(*stb, elem -> stack);
		x = elem -> mov_b;
		while (--x > -1)
		{
			if (a == 1)
				rotate_a_b(stb, 'b');
			if (a == 0)
				reverse_rotate_a_b(stb, 'b');
		}
	}
}

void	push(t_nvr **sta, t_nvr **stb, t_nvr *elem)
{
	int	jbl;
	int	tout;

	if (elem -> mov_a < elem -> mov_b)
		jbl = elem -> mov_a;
	else
		jbl = elem -> mov_b;
	if (elem -> mov_a < elem -> mov_b)
		tout = elem -> mov_b;
	else
		tout = elem -> mov_a;
	if (elem -> mark == 0 || elem -> mark == 2)
	{
		tout = tout - jbl;
		while (--jbl > -1)
		{
			if (elem -> mark == 0)
				rotate_rr(sta, stb);
			if (elem -> mark == 2)
				reverse_rotate_rrr(sta, stb);
		}
	}
	prepar_a(sta, elem);
	prepar_b(stb, elem);
	push_a_b(stb, sta, 'b');
}

void	return_to_sta(t_nvr **sta, t_nvr **stb)
{
	t_nvr	*final;
	t_nvr	*elem;

	final = NULL;
	while (*stb)
	{
		final = final_mov(sta, stb);
		elem = find_best_mov(final);
		push(sta, stb, elem);
		ft_lstdelone(&final);
	}
}
