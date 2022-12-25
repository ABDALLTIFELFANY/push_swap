/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:01:28 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/25 14:03:36 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_mov(t_nvr **all)
{
	t_var	x;

	x.big = (*all)-> stack;
	x.head = (*all)-> next -> stack;
	while ((*all)-> next -> next)
	{
		x.node = (*all);
		while (x.node -> next -> next)
		{
			if (x.node -> next -> next -> stack < x.big)
			{
				x.big = x.node -> next -> next -> stack;
				x.head = x.node -> next -> next -> next -> stack;
			}
			x.node = x.node -> next -> next;
		}
		(*all) = (*all)-> next -> next;
	}
	return (x.head);
}

void	check_a(t_nvr **sta, int kk, char c)
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
