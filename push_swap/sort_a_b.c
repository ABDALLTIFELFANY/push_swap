/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:00:51 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/25 17:20:51 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_in_stb(t_nvr *stb, int elem, int *count)
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
		*count += size - a;
	else
		*count += a;
}

int	count_in_sta(t_nvr *taa, t_nvr *tab, int elem, int size)
{
	t_mix	m;

	m.reg = taa;
	m.a = -1;
	m.min = find_small(taa);
	m.big = find_big_one(taa);
	m.last = link_lst(&taa);
	while (++m.a < size)
	{
		if (taa-> stack < elem && taa-> next -> stack > elem)
		{
			m.a++;
			break ;
		}
		if (taa-> stack == m.min && elem < m.min)
			break ;
		if (taa -> stack == m.big && elem > m.big)
			break ;
		taa = taa -> next;
	}
	if (m.a > size / 2)
		m.a = size - m.a;
	count_in_stb(tab, elem, &m.a);
	d_link(&taa, m.last, m.reg);
	return (m.a);
}

t_nvr	*moves_place(t_nvr *ldb, int min, int a)
{
	insert(&ldb, min);
	insert(&ldb, a);
	return (ldb);
}

t_nvr	*count_mv(t_nvr *sta, t_nvr *stb)
{
	int		val;
	t_nvr	*head;
	t_nvr	*save;
	t_nvr	*head1;

	head = sta;
	head1 = stb;
	save = NULL;
	val = count_in_sta(head, stb, head1-> stack, ft_lstsize(sta));
	save = moves_place(save, val, head1-> stack);
	head1 = head1-> next;
	while (head1)
	{
		val = count_in_sta(head, stb, head1-> stack, ft_lstsize(sta));
		save = moves_place(save, val, head1-> stack);
		head1 = head1-> next;
	}
	return (save);
}
