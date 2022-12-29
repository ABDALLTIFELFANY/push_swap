/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:45:37 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/26 19:12:22 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_stb(t_nvr *stb, int elem, int *mark)
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
		a += size - a;
        *mark++;
    }
	else
		a += a;
    return a;
}

int	count_sta(t_nvr *taa, int elem, int size, int *mark)
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
    {
		m.a = size - m.a;
        *mark++;
    }
	d_link(&taa, m.last, m.reg);
    //*mark * -1;
	return (m.a);
}
void final_mov(t_nvr **sta, t_nvr **stb, int size)
{
    int mark;
    t_nvr *head;
    int x;
    int a;
    int y;

    mark = 0;
    head = *stb;
    x = count_sta(sta,head -> stack, ft_lstsize(stb), &mark);
    y = count_stb(sta,head -> stack,&mark);
    printf("x -> %d\n", x);
    printf("y -> %d\n", y);
    printf("mark -> %d\n", mark);
}
