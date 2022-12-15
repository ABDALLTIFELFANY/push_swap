/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_instra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:42:07 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/15 20:18:06 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_instra(t_nvr *a, t_nvr *b)
{
    t_nvr *temp;

    push_a_b(&a,&b,'a');
	push_a_b(&a,&b,'a');
	push_a_b(&a,&b,'a');
	push_a_b(&a,&b,'a');
	push_a_b(&a,&b,'a');
	swap_ss(&a->stack,&a->next->stack,&b->stack,&b->next->stack);
	rotate_rr(&a,&b);
	reverse_rotate_rrr(&a,&b);
	temp = a;
	while(a)
	{
		printf("|%d|\n", a -> stack);
		a = a -> next;
	}
	printf("---\n");
	printf(" a \n");
	a = temp;
	printf("---\n");
	while(b)
	{
		printf("|%d|\n", b -> stack);
		b = b -> next;
	}
	printf("---\n");
	printf(" b \n");
}