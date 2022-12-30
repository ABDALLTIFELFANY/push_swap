/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:24:33 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/30 13:16:52 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
