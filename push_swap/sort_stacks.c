/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:24:33 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 16:19:56 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_and_rotate(t_nvr **sta, t_nvr **stb, int kk, char c)
{
	int	jbl;

	jbl = half(*sta, kk);
	while (1)
	{
		if ((*sta)-> stack == kk)
			break ;
		if (jbl == 1)
			rotate_a_b(&*sta, c);
		if (jbl == 0)
			reverse_rotate_a_b(&*sta, c);
	}
	push_a_b(&*sta, &*stb, c);
}

void	sort_stacks(t_nvr **sta, t_nvr **stb, t_nvr **lis)
{
	t_norm	m;

	m.head = *sta;
	m.kk = 0;
	while (m.head)
	{
		m.head1 = (*lis);
		while (m.head1)
		{
			if (m.head-> stack == m.head1 -> stack)
			{
				m.kk = 1;
				break ;
			}
			m.head1 = m.head1-> next;
		}
		if (m.kk == 0)
		{
			check_and_rotate(&*sta, &*stb, m.head-> stack, 'a');
			m.head = *sta;
		}
		else
			m.head = m.head -> next;
		m.kk = 0;
	}
}

// void	find_it(t_nvr **tab, int kk, int size)
// {
// 	int	x;

// 	x = 0;
// 	while (x < size)
// 	{
// 		if ((*tab)-> stack == kk)
// 		{
// 			(*tab) = (*tab)-> next;
// 			break ;
// 		}
// 		(*tab) = (*tab)-> next;
// 		x++;
// 	}
// }

// t_nvr	*index_s(t_nvr *lst, int inx)
// {
// 	lst = NULL;
// 	insert(&lst, inx);
// 	return (lst);
// }

// t_nvr	*find_who_p_b(t_nvr *sta, int kk, int size)
// {
// 	t_var2	x;

// 	x.x = -1;
// 	x.last = link_lst(&sta);
// 	x.indexs = index_s(x.indexs, kk);
// 	x.reg = sta;
// 	while (++x.x < size)
// 	{
// 		x.node = sta;
// 		find_it(&x.node, kk, size);
// 		x.y = x.x;
// 		while (++x.y < size)
// 		{
// 			if (x.node-> stack > kk)
// 			{
// 				x.indexs = index_s(x.indexs, x.node-> stack);
// 				kk = x.node-> stack;
// 				break ;
// 			}
// 			x.node = x.node-> next;
// 		}
// 		sta = sta-> next;
// 	}
// 	d_link(&sta, x.last, x.reg);
// 	return (x.indexs);
// }
